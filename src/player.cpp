#include "player.hpp"
#include <sol/state.hpp>

Player::Player(std::string name, Position position)
    : name(name)
    , position(position) {}

void Player::bind(sol::state& lua) {
  sol::usertype<Player> binder = lua.new_usertype<Player>(Player::objectName, sol::no_constructor);
  binder.set("name", &Player::name);
  binder.set("position", &Player::position);
  binder.set("move", &Player::move);
  binder.set(sol::meta_function::to_string, &Player::str);
}

Position Player::move(Vector delta) {
  this->position += delta;
  return this->position;
}
