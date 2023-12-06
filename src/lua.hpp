#pragma once
#define SOL_ALL_SAFETIES_ON 1
#include <sol/state.hpp>

class Lua {
public:
  using super = sol::state;
  Lua();

  void init();

private:
  sol::state lua;
  sol::optional<sol::function> onInit;
};
