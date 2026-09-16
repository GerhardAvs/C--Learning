#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Point2D {
public:
  Point2D(double x, double y);
  string toString();
  double toDouble();
  double distanceTo(Point2D that);
private:
  double x;
  double y;
};

Point2D::Point2D(double x, double y)
{
  this->x = x;
  this->y = y;
}

double Point2D::distanceTo(Point2D that)
{
  double dx = this->x - that.x;
  double dy = this->y - that.y;
  return sqrt(dx * dx + dy * dy);
}

// No aportan nada útil para este lab, pero se dejan implementados
// por si la interfaz exigida los necesita presentes.
string Point2D::toString()
{
  return "(" + to_string(x) + ", " + to_string(y) + ")";
}

double Point2D::toDouble()
{
  return sqrt(x * x + y * y);   // distancia al origen, a falta de mejor definición
}

// Lee un número y descarta una coma opcional que venga justo después
double readCoordinate(istream& in)
{
  double value;
  in >> value;

  if (in.peek() == ',')
    in.ignore();

  return value;
}

int main() {
  double x1 = readCoordinate(cin);
  double y1 = readCoordinate(cin);
  double x2 = readCoordinate(cin);
  double y2 = readCoordinate(cin);

  Point2D p1(x1, y1);
  Point2D p2(x2, y2);

  cout << p1.distanceTo(p2) << endl;

  return 0;
}