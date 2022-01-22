#include <iostream>
using namespace std;

class Point {
private:
  double x,y; // private data members
public:
    Point() = default;
    // Point(int initx, int inity) {
    //   x = initx;
    //   y = inity;
    // }
    Point(double initx, double inity) : x(initx), y(inity) {
    }

    double getX() {
      return x;
    }

    void setX(double newX) {
      x = newX;
    }

    double getY() {
      return y;
    }

    void setY(double newY) {
      y = newY;
    }

    Point operator*(double scaleFactor) {
      Point result(x * scaleFactor, y * scaleFactor);
      return result;
    }

};


ostream& operator<<(ostream& output, Point pt) {
//  output << "(" << pt.getX() << "," << pt.getY() << ")";
  output << "(" << &pt<< ")";
  return output;
}

int main() {
  Point myPoint;
  Point otherPoint(10,5), pt(1,2), more(3,4);
  Point scaledPoint = otherPoint * 0.5;

  cout << scaledPoint << endl;

}
