#include <iostream>
#include <memory>
#include <vector>
#include "log.h"
#include "Circle.h"
#include "Square.h"

int main(void) {
  // Type declarations
  using shape_ptr = std::shared_ptr<Shape>;

  log_heading("##  Derived class pointer construction  ##");
  // Shape instance pointers
  log_indentNext("This should call Circle::Circle()");
  auto circle_ptr = std::make_unique<Circle>();
  log_popIndentLevel();

  log_indentNext("This should call Square::Square()");
  auto square_ptr = std::make_unique<Square>();
  log_popIndentLevel();

  log_heading(
      "##  Base class pointer construction using make_unique<Derived>  ##");
  log_indentNext("This should call Circle::Circle()");
  shape_ptr shape_ptr_to_circle = std::make_unique<Circle>();
  log_popIndentLevel();

  log_indentNext("This should call Square::Square()");
  shape_ptr shape_ptr_to_square = std::make_unique<Square>();
  log_popIndentLevel();

  log_heading("##  make_unique<Derived> using copy constructor  ##");
  log_indentNext("This should call Circle::Circle(const Circle&)");
  auto dup_circle_ptr = std::make_unique<Circle>(*circle_ptr);
  log_popIndentLevel();

  log_indentNext("This should call Square::Square(const Square&)");
  auto dup_square_ptr = std::make_unique<Square>(*square_ptr);
  log_popIndentLevel();

  /**
   * This code doesn't work because std::make_unique<T>(Args&&...args) calls the
   * following constructor:
   *
   * T::T(Args&&...args).
   *
   * If T::T(Args&&) doesn't exist, then the compiler throws an error. Given
   * that make_unique doesn't work on the base class as it is abstract, we need
   * another solution.
   */
  // log_heading("##  make_unique<Base> using copy constructor  ##");
  // std::cout << "This should call Circle::Circle(const Circle&)" << std::endl;
  // auto dup_shape_ptr_to_circle = std::make_unique<Shape>(*circle_ptr);

  // std::cout << "This should call Square::Square(const Square&)" << std::endl;
  // auto dup_shape_ptr_to_square = std::make_unique<Shape>(*square_ptr);

  log_heading("! DESTRUCTION !");
  return 0;
}