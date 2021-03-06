#include "Square.h"

Square::Square() { log("Square::Square()"); }

Square::Square(const Square& sqr) : Shape(sqr) {
  log("Square::Square(const Square&)");
}

Square::~Square() { log("Square::~Square()"); }

int Square::numberOfSides() const { return _nSides; }

const int Square::_nSides = 4;

std::unique_ptr<Shape> Square::clone() const { return std::make_unique<Square>(*this); }