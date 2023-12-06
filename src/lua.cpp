#include "lua.hpp"
#include "position.hpp"

Lua::Lua() {
  this->lua.open_libraries(sol::lib::base, sol::lib::math);

  Position::bind(this->lua);

  this->lua.set("Events", sol::new_table());
  this->lua["Events"]["on_init"] = [this](sol::function callback) { this->onInit = callback; };

  this->lua.script_file("lua/control.lua");
}

void Lua::init() {
  if (this->onInit)
    this->onInit->call();
}
