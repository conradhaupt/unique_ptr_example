#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape {
 public:
  Square();
  Square(const Square& sqr);
  virtual ~Square() override;
  int numberOfSides() const override;

  std::unique_ptr<Shape> clone() const override;

 private:
  const static int _nSides;
};
#endif