# unique_ptr example

This code shows off how std::unique_ptr can be used with copies etc. See below for how to compile.

## Requirements

- gcc
- cmake
- make

## Build process

Inside the root directory of the repo, run the following commands.

```bash
mkdir build
cd build
cmake ..
make
./uniquePtrExample
```

## Output

```txt
##  Derived class pointer construction  ##

This should call Circle::Circle()
  Shape::Shape()
  Circle::Circle()
This should call Square::Square()
  Shape::Shape()
  Square::Square()

##  Base class pointer construction using make_unique<Derived>  ##

This should call Circle::Circle()
  Shape::Shape()
  Circle::Circle()
This should call Square::Square()
  Shape::Shape()
  Square::Square()

##  make_unique<Derived> using copy constructor  ##

This should call Circle::Circle(const Circle&)
  Shape::Shape(const Shape&)
  Circle::Circle(const Circle&)
This should call Square::Square(const Square&)
  Shape::Shape(const Shape&)
  Square::Square(const Square&)

##  Creating a vector of unique_ptrs to shapes and derived classes  ##

Shape::Shape()
Circle::Circle()
Shape::Shape()
Square::Square()
Shape::Shape()
Circle::Circle()

##  Cloning the middle pointer  ##

Shape::Shape(const Shape&)
Square::Square(const Square&)

##  The result of this range-based for loop should be 1,4,1,4  ##

  1,4,1,4

! DESTRUCTION !

Circle::~Circle()
Shape::~Shape()

Square::~Square()
Shape::~Shape()

Circle::~Circle()
Shape::~Shape()

Square::~Square()
Shape::~Shape()

Square::~Square()
Shape::~Shape()

Circle::~Circle()
Shape::~Shape()

Square::~Square()
Shape::~Shape()

Circle::~Circle()
Shape::~Shape()

Square::~Square()
Shape::~Shape()

Circle::~Circle()
Shape::~Shape()
```