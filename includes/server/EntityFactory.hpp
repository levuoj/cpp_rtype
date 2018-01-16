//
// Created by pashervz on 12/01/18.
//

#ifndef CPP_RTYPE_ENTITYFACTORY_HPP
#define CPP_RTYPE_ENTITYFACTORY_HPP

#include <unordered_map>
#include "server/APlayer.hpp"
#include "utils/Loader.hpp"
#include "EEntityType.hpp"

namespace FF
{
  class EntityFactory
  {
  private:
    Loader<AEntity>                                 _loader;
    int                                             _idEntity = 0;
    std::unordered_map<EEntityType, const char *>   _pathMap =
            {
                    {PLAYER, "../lib/libETPlayer.so"},
                    {MONSTER, "../lib/libETMonster.so"},
                    {LEVEL1, "../lib/libETLevel1.so"}
            };
  public:
    EntityFactory() = default;

    ~EntityFactory() = default;

    template<EEntityType Type>
    std::shared_ptr<AEntity>                 generate()
    {
      if (!_loader.isOpen(_pathMap.at(Type)))
        _loader.Open(_pathMap.at(Type));
      return (_loader.Load(_pathMap.at(Type), "create"));
    }
  };
}

#endif //CPP_RTYPE_ENTITYFACTORY_HPP
