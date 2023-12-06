#pragma once
#include <format>
#include <string>
namespace sol {
class state;
}

class Position {
public:
  Position(double x = 0, double y = 0)
      : x(x)
      , y(y) {}

  static void bind(sol::state& lua);

  Position operator+(const Position& other) { return Position(this->x + other.x, this->y + other.y); }
  Position operator-(const Position& other) { return Position(this->x - other.x, this->y - other.y); }
  Position operator*(const Position& other) { return Position(this->x * other.x, this->y * other.y); }
  Position operator/(const Position& other) { return Position(this->x / other.x, this->y / other.y); }

  std::string str() { return std::format("Position({}, {})", this->x, this->y); }

  double x = 0;
  double y = 0;
};
