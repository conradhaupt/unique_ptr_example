#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape {
 public:
  int numberOfSides() const override;

 private:
  const static int _nSides;
};
#endif