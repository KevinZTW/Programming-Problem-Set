#include <iostream>
#include <vector>

class Animal {};

class Cat : public Animal {};

namespace shapes {
using namespace std;
struct Point {
  int x;
  int y;
  Point(int a, int b) : x(a), y(b){};
};

class Shape {
 public:
  // virtual func() = 0 pure virtual function 表示在我這個 class
  // 不必實作，但是繼承我的人要實作
  virtual Point center() const = 0;
  virtual void shift(Point dxy) = 0;
  virtual void rotate(int angle) = 0;
  virtual void draw() const = 0;
  virtual ~Shape() {}  // destruction
};

class Circle : public Shape {
 private:
  Point c;
  int r;

 public:
  Circle() : c(Point(2, 4)), r(66){};

  Point center() const override { return c; };
  void shift(Point dxy) override{};
  void rotate(int angle) override{};
  void draw() const override { cout << "This is an circle" << endl; };

  ~Circle(){};
};
class Square : public Shape {
 private:
  Point c;
  int r;

 public:
  Square() : c(Point(2, 4)), r(66){};

  Point center() const override { return c; };
  void shift(Point dxy) override{};
  void rotate(int angle) override{};
  void draw() const override { cout << "This is an square" << endl; };

  ~Square(){};
};

}  // namespace shapes

using namespace std;
using namespace shapes;
int main(void) {
  Circle c1;
  Square s1;
  //測試只能以指針的方式使用
  vector<Shape*> v{&c1, &s1};

  for (auto i : v) i->draw();
  Cat cat1;
  vector<Animal>{cat1};
}