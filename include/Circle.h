#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
 public:
  int numberOfSides() const override;
};

#endif