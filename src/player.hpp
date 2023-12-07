#pragma once
#include "position.hpp"
#include "vector.hpp"

class Player {
public:
  Player(std::string name, Position position = Position());

  static void bind(sol::state& lua);
  static constexpr const char* objectName = "Player";
  std::string str() {
    return std::format("{}('{}', {}, {})", Player::objectName, this->name, this->position.x, this->position.y);
  }

  Position move(Vector delta);

  std::string name;
  Position position;
};
