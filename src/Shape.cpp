#include "Shape.h"

Shape::Shape() { log("Shape::Shape()"); }

Shape::Shape(const Shape& shp) { log("Shape::Shape(const Shape&)"); }

Shape::~Shape() { log("Shape::~Shape()\n"); }

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