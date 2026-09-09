/*
Level of difficulty
Easy

Objectives
Familiarize the student with:

creating setter access methods;
limiting the range of accepted values in access methods.
Scenario
One important aspect of object-oriented programming is data encapsulation.

This is a complicated term for protecting the data of an object.

But why should you protect the data? Look at the code below.

As we can see, this isn't correct. But you can fix this!

Hide the area and side members using the keyword private;
add a public method set_side to the Square class that will update both fields;
set_side should also ignore the change if the argument is less than 0;
change the print function implementation into a public method of Square.
*/

#include <iostream>
#include <string>

using namespace std;

class Square
{
public:
  Square(double side);
  void set_side(double newSide);
  void print();

private:
  double side;
  double area;
};

Square::Square(double side)
{
  this->side = side;
  this->area = side * side;
}

void Square::set_side(double newSide)
{
  if(newSide < 0){
    return; // ignora el cambio si es negativo
  }
  side = newSide;
  area = newSide * newSide;
}

void Square::print()
{
  cout << "Square: side=" << side << " area=" << area << endl;
}


int main()
{
  Square s(4);

  s.print();

  s.set_side(2.0);
  s.print();

  s.set_side(-33.0);
  s.print();

  return 0;
}