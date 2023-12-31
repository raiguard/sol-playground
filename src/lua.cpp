#include "lua.hpp"
#include "player.hpp"
#include "position.hpp"

Lua::Lua() {
  this->lua.open_libraries(sol::lib::base, sol::lib::math);

  Player::bind(this->lua);
  Position::bind(this->lua);
  Vector::bind(this->lua);

  this->lua.set("Events", sol::new_table());
  this->lua["Events"]["on_init"] = [this](sol::function callback) { this->onInit = callback; };
  this->lua["Events"]["on_player_created"] = [this](sol::function callback) { this->onPlayerCreated = callback; };
  this->lua["Events"]["on_tick"] = [this](sol::function callback) { this->onTick = callback; };

  this->lua.script_file("lua/control.lua");
}

void Lua::init() {
  if (this->onInit)
    this->onInit->call();
}
