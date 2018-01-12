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
    const char *                                                      _path;
    void                                                              *_handle = NULL;
    std::unordered_map<int, T*>                                        _instances;

public:
    Loader() : _path("") {}
    explicit Loader(const char *path) : _path(path) {}
    ~Loader() {
        Close();
    }

    int            Open() {
        this->_handle = dlopen(_path, RTLD_LAZY);
        if (this->_handle == NULL) {
            std::cerr << "DLopen failed" << std::endl;
            return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
    }

    void            Close() {
        if (this->_handle != NULL)
            dlclose(this->_handle);
    }

    int            Load(const char *entryPoint, int ID) {
        T*                      (*func)();

        func = reinterpret_cast<T *(*)()>(dlsym(this->_handle, entryPoint));
        if (func == NULL) {
            std::cerr << "DLsym failed" << std::endl;
            return EXIT_FAILURE;
        }
        this->_instances.insert(std::make_pair(ID, func()));
        return EXIT_SUCCESS;
    }

    void                    setPath(const char *path) { _path = path; }

    T                       *getInstance(int ID) const {
        if (_instances.find(ID) != _instances.end()) {
            return ((_instances.at(ID)));
        }
        return nullptr;
    }

    bool                    isOpen() const { return (this->_handle == NULL); }
};

#endif //CPP_RTYPE_LOADER_HPP
