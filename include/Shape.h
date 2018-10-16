#ifndef MYCLASS_H
#define MYCLASS_H

/**
 * @brief Abstract shape class
 *
 */
class Shape {
 public:
  virtual ~Shape();

  virtual int numberOfSides() const = 0;

  // Comparison operators
  bool operator==(const Shape& rhs);
  bool operator!=(const Shape& rhs);
  bool operator<(const Shape& rhs);
  bool operator>(const Shape& rhs);
  bool operator<=(const Shape& rhs);
  bool operator>=(const Shape& rhs);
};

#endif