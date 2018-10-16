#ifndef SHAPE_H
#define SHAPE_H
#include <memory>
#include "log.h"

/**
 * @brief Abstract shape class
 *
 */
class Shape {
 public:
  Shape();
  Shape(const Shape& shp);

  virtual ~Shape();

  virtual int numberOfSides() const = 0;

  // Comparison operators
  bool operator==(const Shape& rhs);
  bool operator!=(const Shape& rhs);
  bool operator<(const Shape& rhs);
  bool operator>(const Shape& rhs);
  bool operator<=(const Shape& rhs);
  bool operator>=(const Shape& rhs);

  virtual std::unique_ptr<Shape> clone() const = 0;
};

#endif