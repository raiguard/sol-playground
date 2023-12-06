#include "position.hpp"
#include <format>
#include <sol/state.hpp>

void Position::bind(sol::state& lua) {
  auto constructors = sol::constructors<Position(), Position(double), Position(double, double)>();
  sol::usertype<Position> binder = lua.new_usertype<Position>("Position", constructors);
  binder.set("x", &Position::x);
  binder.set("y", &Position::y);
  binder.set("__add", &Position::operator+);
  binder.set("__sub", &Position::operator-);
  binder.set("__mul", &Position::operator*);
  binder.set("__div", &Position::operator/);
  binder.set("__tostring", &Position::str);
}
