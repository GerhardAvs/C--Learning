#include <iostream>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double toDouble();
  // ...
  double distanceTo(Point2D that);
private:
  double x;
  double y;
};

// implement Point2D methods