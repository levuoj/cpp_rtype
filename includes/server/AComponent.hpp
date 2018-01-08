//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_ICOMPONENT_HPP
#define CPP_RTYPE_ICOMPONENT_HPP

#include <memory>

class AEntity;

class AComponent
{
private:
    int                         _id;
    std::unique_ptr<AEntity>    _entity;
    bool                        _status;

public:
    AComponent(int id, AEntity const & entity) : _id(id), _entity(std::unique_ptr<AEntity>(entity)), _status(true) {}
    virtual ~AComponent();

    virtual void    init() = 0;
    virtual void    draw() = 0;
    virtual void    update() = 0;
    void            setStatus(bool status) { _status = status; }
    bool            getStatus() const { return _status; }
    int             getId() const { return _id; }
};

#endif //CPP_RTYPE_ICOMPONENT_HPP
