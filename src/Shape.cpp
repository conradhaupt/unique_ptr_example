#include "Shape.h"

Shape::~Shape() {}

bool Shape::operator==(const Shape& rhs) {
  return numberOfSides() == rhs.numberOfSides();
}
bool Shape::operator!=(const Shape& rhs) {
  return numberOfSides() != rhs.numberOfSides();
}
bool Shape::operator<(const Shape& rhs) {
  return numberOfSides() < rhs.numberOfSides();
}
bool Shape::operator>(const Shape& rhs) {
  return numberOfSides() > rhs.numberOfSides();
}
bool Shape::operator<=(const Shape& rhs) {
  return numberOfSides() <= rhs.numberOfSides();
}
bool Shape::operator>=(const Shape& rhs) {
  return numberOfSides() >= rhs.numberOfSides();
}