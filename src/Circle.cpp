#include "Circle.h"

Circle::Circle() { log("Circle::Circle()"); }

Circle::Circle(const Circle& crcl) : Shape(crcl) {
  log("Circle::Circle(const Circle&)");
}

Circle::~Circle() { log("Circle::~Circle()"); }

int Circle::numberOfSides() const { return 1; }

std::unique_ptr<Shape> Circle::clone() const {
  return std::make_unique<Circle>(*this);
}