#pragma once
#include <sol/state.hpp>

class Lua {
public:
  using super = sol::state;
  Lua();

  void init();

  sol::state lua;
  sol::optional<sol::function> onInit;
  sol::optional<sol::function> onPlayerCreated;
  sol::optional<sol::function> onTick;
};
