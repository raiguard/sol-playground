#pragma once
#include "position.hpp"

class Vector {
public:
  Vector() = default;
  Vector(double x, double y)
      : target(x, y) {}
  Vector(Position target)
      : target(target) {}
  Vector(Position from, Position to)
      : target(to - from) {}

  static void bind(sol::state& lua);
  static constexpr const char* objectName = "Vector";
  std::string str() { return std::format("{}({}, {})", Vector::objectName, this->target.x, this->target.y); }

  Vector operator+(const Vector& other) { return Vector(this->target + other.target); }
  Vector operator-(const Vector& other) { return Vector(this->target - other.target); }
  Vector operator*(double scalar) { return Vector(this->target * scalar); }
  Vector operator/(double scalar) { return Vector(this->target / scalar); }

  constexpr void operator+=(const Position& other) { this->target += other; }
  constexpr void operator-=(const Position& other) { this->target -= other; }
  void operator*=(double scalar) { this->target *= scalar; }
  void operator/=(double scalar) { this->target /= scalar; }

  double getMagnitude();
  void setMagnitude(double magnitude);

  Vector getNorm();

  Position target;
};
