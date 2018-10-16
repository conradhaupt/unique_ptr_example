#include <iostream>
#include <memory>
#include <vector>
#include "Circle.h"
#include "Square.h"
#include "log.h"

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

  /**
   * This code shows how to be able to make a derived copy of a unique_ptr.
   */

  // Create a vector of base unique_ptrs from unique_ptrs to derived classes
  log_heading(
      "##  Creating a vector of unique_ptrs to shapes and derived classes  ##");
  std::vector<shape_ptr> shape_vctr;
  shape_vctr.emplace_back(std::make_unique<Circle>());
  shape_vctr.emplace_back(std::make_unique<Square>());
  shape_vctr.emplace_back(std::make_unique<Circle>());

  log_heading("##  Cloning the middle pointer  ##");
  // Copy the middle pointer to a new pointer
  shape_vctr.emplace_back(shape_vctr.at(1)->clone());

  log_heading(
      "##  The result of this range-based for loop should be 1,4,1,4  ##");
  std::cout << "\t";
  bool cout_comma = false;
  for (auto& shp_ptr : shape_vctr) {
    if (cout_comma) std::cout << ",";
    std::cout << shp_ptr->numberOfSides();
    cout_comma = true;
  }
  std::cout << std::endl;

  log_heading("! DESTRUCTION !");
  return 0;
}