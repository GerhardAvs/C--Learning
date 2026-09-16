/*
Level of difficulty
Medium

Objectives
Familiarize the student with:

creating getter access methods;
different strategies for obtaining derived data.
Scenario
One aspect of encapsulation is setting the data in the object, but there is another aspect to it.

We can also take different approaches to getting the data out of the object.

In the previous example, we asked for the area to be recalculated every time the side was changed. When calculating the square of a number, this is not too costly, but in the case of a more complicated operation, this may be wasteful.
A more ad hoc approach would be to calculate the area only when needed, i.e. not store it in the object at all. This way we don't recalculate the value on each side change; but again, more costly operations may become a burden.
Yet another, lazy, approach would be to recalculate the value only when needed. We can add a small bit of information to the object that will tell us that the side has changed. When asked for the area, we can check if the side has changed since the last recalculation; if not, we simply return the stored value, and otherwise we recalculate the area and clear the information about side changes.
See the class definitions below and implement the two new approaches to the above problem.
*/

#include <iostream>

using namespace std;

// Estrategia "ad hoc": no guardamos area, la calculamos cada vez que se pide
class AdHocSquare
{
public:
  AdHocSquare(double side);
  void set_side(double side);
  double get_area();
private:
  double    side;
};

AdHocSquare::AdHocSquare(double side)
{
  this->side = side;
}

void AdHocSquare::set_side(double side)
{
  if (side < 0)
    return;

  this->side = side;
}

double AdHocSquare::get_area()
{
  return side * side;   // se calcula solo cuando alguien la pide
}


// Estrategia "lazy": guardamos area, pero solo la recalculamos si side cambió
class LazySquare
{
public:
  LazySquare(double side);
  void set_side(double side);
  double get_area();
private:
  double    side;
  double    area;
  bool      side_changed;
};

LazySquare::LazySquare(double side)
{
  this->side = side;
  this->area = side * side;
  this->side_changed = false;
}

void LazySquare::set_side(double side)
{
  if (side < 0)
    return;

  this->side = side;
  this->side_changed = true;   // marcamos que hay que recalcular
}

double LazySquare::get_area()
{
  if (side_changed)
  {
    area = side * side;        // recalculamos solo ahora
    side_changed = false;      // y limpiamos la marca
  }

  return area;
}


int main()
{
  AdHocSquare a(4);
  cout << "AdHoc area: " << a.get_area() << endl;
  a.set_side(2.0);
  cout << "AdHoc area: " << a.get_area() << endl;

  LazySquare l(4);
  cout << "Lazy area: " << l.get_area() << endl;
  l.set_side(2.0);
  cout << "Lazy area: " << l.get_area() << endl;
  l.set_side(-33.0);   // se ignora
  cout << "Lazy area: " << l.get_area() << endl;

  return 0;
}