#include <iostream>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double getX();
  double getY();
  // ...
private:
  double x;
  double y;
};

class Line2D{
public:
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  string toString();
  bool contains(Point2D point);
  // ...
private:
  double slope;
  double y_intercept;
};

// implement Point2D and Line2D methods