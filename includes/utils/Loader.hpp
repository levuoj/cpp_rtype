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
#include "Error.hpp"

template<typename T>
class Loader {
private:
    std::unordered_map<const char *, void *>                                _handles;

public:
    Loader() = default;
    ~Loader() { CloseAll(); }

    int            Open(const char *path)
    {
        void        *handle = nullptr;

        handle = dlopen(path, RTLD_LAZY);
        if (handle == nullptr) {
            throw Error("Open " + std::string(path) + " failed");
        }
        _handles[path] = handle;
        return EXIT_SUCCESS;
    }

    void            Close(const char *path)
    {
        if (_handles.find(path) != _handles.end())
        {
            if (_handles.at(path) != NULL)
                dlclose(_handles.at(path));
        }
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
            throw Error("Cannot find " + std::string(path));
        func = reinterpret_cast<T *(*)()>(dlsym(_handles.at(path), entryPoint));
        if (func == nullptr)
            throw Error("Cannot load " + std::string(path) + " with entryPoint " + std::string(entryPoint));
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
