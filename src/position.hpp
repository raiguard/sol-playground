#pragma once
#include <format>
#include <string>
namespace sol {
class state;
}
class Vector;

class Position {
public:
  Position() = default;
  Position(double xy)
      : x(xy)
      , y(xy) {}
  Position(double x, double y)
      : x(x)
      , y(y) {}
  Position(Vector vec);

  static void bind(sol::state& lua);
  static constexpr const char* objectName = "Position";
  std::string str() { return std::format("{}({}, {})", Position::objectName, this->x, this->y); }

  Position operator+(const Position& other) { return Position(this->x + other.x, this->y + other.y); }
  Position operator-(const Position& other) { return Position(this->x - other.x, this->y - other.y); }
  Position operator*(const Position& other) { return Position(this->x * other.x, this->y * other.y); }
  Position operator/(const Position& other) { return Position(this->x / other.x, this->y / other.y); }

  constexpr void operator+=(const Position& other) {
    this->x += other.x;
    this->y += other.y;
  }
  constexpr void operator-=(const Position& other) {
    this->x -= other.x;
    this->y -= other.y;
  }
  constexpr void operator*=(const Position& other) {
    this->x *= other.x;
    this->y *= other.y;
  }
  constexpr void operator/=(const Position& other) {
    this->x /= other.x;
    this->y /= other.y;
  }

  constexpr std::partial_ordering operator<=>(const Position& other) const = default;

  Position abs();
  double distanceTo(const Position& other);

  double x = 0;
  double y = 0;
};
