#include "vector.hpp"
#include <sol/state.hpp>

void Vector::bind(sol::state& lua) {
  auto constructors =
      sol::constructors<Vector(), Vector(double, double), Vector(Position), Vector(Position, Position)>();
  sol::usertype<Vector> binder = lua.new_usertype<Vector>(Vector::objectName, constructors);
  binder.set("magnitude", sol::property(&Vector::getMagnitude, &Vector::setMagnitude));
  binder.set("get_norm", &Vector::getNorm);
  binder.set("__add", &Vector::operator+);
  binder.set("__sub", &Vector::operator-);
  binder.set("__mul", &Vector::operator*);
  binder.set("__div", &Vector::operator/);
  binder.set("__tostring", &Vector::str);
}

double Vector::getMagnitude() {
  return std::sqrt((this->target.x * this->target.x) + (this->target.y * this->target.y));
}

void Vector::setMagnitude(double magnitude) {
  *this = this->getNorm() * magnitude;
}

Vector Vector::getNorm() {
  if (this->getMagnitude() == 0)
    return Vector();
  return *this / this->getMagnitude();
}
