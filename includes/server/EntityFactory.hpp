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
  class EntityFactory {
  private:
      Loader<AEntity> _loader;
      std::unordered_map<EEntityType, const char *> _pathMap =
              {
                      {PLAYER,       "../lib/libETPlayer.so"},
                      {MAP,          "../lib/libETLevel1.so"},
                      {BASICMONSTER, "../lib/libETBasicMonster.so"}
              };
  public:
      EntityFactory() = default;

      ~EntityFactory() = default;

      std::shared_ptr<AEntity> generate(EEntityType type)
      {
          if (!_loader.isOpen(_pathMap.at(type)))
          {
              if (_loader.Open(_pathMap.at(type)) == EXIT_FAILURE)
                  return nullptr;
          }
          return (_loader.Load(_pathMap.at(type), "create"));
      }
  };
}

#endif //CPP_RTYPE_ENTITYFACTORY_HPP
