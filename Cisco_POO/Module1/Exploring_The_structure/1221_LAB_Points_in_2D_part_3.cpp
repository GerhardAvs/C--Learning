#include <iostream>
#include <sstream>
#include <cmath>
#include <string>

using namespace std;

const double EPSILON = 1e-9;

class Point2D {
public:
  Point2D(double x, double y);
  string toString();
  double getX();
  double getY();
private:
  double x;
  double y;
};

Point2D::Point2D(double x, double y)
{
  this->x = x;
  this->y = y;
}

double Point2D::getX()
{
  return x;
}

double Point2D::getY()
{
  return y;
}

string Point2D::toString()
{
  ostringstream oss;
  oss << "(" << x << ", " << y << ")";
  return oss.str();
}


class Line2D {
public:
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  string toString();
  bool contains(Point2D point);
private:
  double slope;
  double y_intercept;
};

Line2D::Line2D(double slope, double y_intercept)
{
  this->slope = slope;
  this->y_intercept = y_intercept;
}

Line2D::Line2D(Point2D pointA, Point2D pointB)
{
  double dx = pointB.getX() - pointA.getX();
  double dy = pointB.getY() - pointA.getY();

  slope = dy / dx;
  y_intercept = pointA.getY() - slope * pointA.getX();
}

string Line2D::toString()
{
  ostringstream oss;
  oss << "y = " << slope << "x ";

  if (y_intercept < 0)
    oss << "- " << -y_intercept;
  else
    oss << "+ " << y_intercept;

  return oss.str();
}

bool Line2D::contains(Point2D point)
{
  double expected_y = slope * point.getX() + y_intercept;
  return fabs(expected_y - point.getY()) < EPSILON;
}


int main() {
  double x1, y1, x2, y2, x3, y3;

  cin >> x1 >> y1;
  cin >> x2 >> y2;
  cin >> x3 >> y3;

  Point2D pointA(x1, y1);
  Point2D pointB(x2, y2);
  Point2D pointC(x3, y3);

  Line2D line(pointA, pointB);

  if (line.contains(pointC))
    cout << "collinear" << endl;
  else
    cout << "not collinear" << endl;

  return 0;
}