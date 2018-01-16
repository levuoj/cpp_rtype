//
// Created by pashervz on 05/01/18.
//

#ifndef CPP_RTYPE_LOADER_HPP
#define CPP_RTYPE_LOADER_HPP

#include <memory>
#include <dlfcn.h>
#include <search.h>
#include <iostream>
#include <unordered_map>

template<typename T>
class Loader {
private:
    std::unordered_map<const char *, void *>                                _handles;

public:
    Loader() = default;
    ~Loader() { CloseAll(); }

    int            Open(const char *path)
    {
        void        *handle = NULL;

        handle = dlopen(path, RTLD_LAZY);
        if (handle == NULL) {
            std::cerr << path << ": DLopen failed" << std::endl;
            return EXIT_FAILURE;
        }
        _handles.insert(std::make_pair(path, handle));
        return EXIT_SUCCESS;
    }

    int            Close(const char *path)
    {
        std::cout << path << std::endl;
        if (_handles.find(path) != _handles.end())
        {
            if (_handles.at(path) != NULL) {
                dlclose(_handles.at(path));
                return EXIT_SUCCESS;
            }
        }
        return EXIT_FAILURE;
    }

    void            CloseAll()
    {
        for (auto & it : _handles)
        {
           Close(it.first);
        }
    }

    std::shared_ptr<T>            Load(const char *path, const char *entryPoint) {
        T                         *(*func)();

        if (_handles.find(path) == _handles.end())
            return nullptr;
        func = reinterpret_cast<T *(*)()>(dlsym(_handles.at(path), entryPoint));
        if (func == NULL) {
            std::cerr << "DLsym failed" << std::endl;
            return nullptr;
        }
        return std::shared_ptr<T>(func());
    }

    bool                    isOpen(const char *path) const {
        if (_handles.find(path) != _handles.end()) {
            if (_handles.at(path) != nullptr)
                return true;
        }
        return false;
    }
};

#endif //CPP_RTYPE_LOADER_HPP
