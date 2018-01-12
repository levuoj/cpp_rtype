//
// Created by pashervz on 05/01/18.
//

#ifndef CPP_RTYPE_LOADER_HPP
#define CPP_RTYPE_LOADER_HPP

#include <memory>
#include <dlfcn.h>
#include <search.h>
#include <iostream>

template<typename T>
class Loader {
private:
    const char *                _path;
    void                        *_handle = NULL;
    std::unique_ptr<T>          _instance;

public:
    Loader() : _path("") {}
    explicit Loader(const char *path) : _path(path) {}
    ~Loader() = default;

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

    void            Load(const char *entryPoint) {
        T*                      (*func)();

        func = reinterpret_cast<T *(*)()>(dlsym(this->_handle, entryPoint));
        if (func == NULL)
            std::cerr << "DLsym failed" << std::endl;
        this->_instance = std::unique_ptr<T>(func());
    }

    void                    setPath(const char *path) { _path = path; }
    T                       *getInstance() { return _instance.get(); }
};



#endif //CPP_RTYPE_LOADER_HPP
