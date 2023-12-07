#include "position.hpp"
#include "vector.hpp"
#include <format>
#include <sol/state.hpp>

Position::Position(Vector vec)
    : Position(vec.target) {}

void Position::bind(sol::state& lua) {
  auto constructors = sol::constructors<Position(), Position(double), Position(double, double)>();
  sol::usertype<Position> binder = lua.new_usertype<Position>(Position::objectName, constructors);
  binder.set("x", &Position::x);
  binder.set("y", &Position::y);
  binder.set("abs", &Position::abs);
  binder.set("distance_to", &Position::distanceTo);
  binder.set("__add", &Position::operator+);
  binder.set("__sub", &Position::operator-);
  binder.set("__mul", &Position::operator*);
  binder.set("__div", &Position::operator/);
  binder.set("__tostring", &Position::str);
}

Position Position::abs() {
  return Position(std::abs(this->x), std::abs(this->y));
}

double Position::distanceTo(const Position& other) {
  return Vector(*this, other).getMagnitude();
}
