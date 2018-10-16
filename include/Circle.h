#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
 public:
  Circle();
  Circle(const Circle& crcl);
  virtual ~Circle();
  std::unique_ptr<Shape> clone() const override;
  int numberOfSides() const override;
};

#endif