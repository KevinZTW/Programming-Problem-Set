#include <iostream>
#include <string>

using namespace std;

class Number {
 public:
  Number();
  Number(string n) {
    base = nullptr;
    repeat = 1;
    deduct = 0;
    base_length = n.length();
    str = n;
  };

  Number* extend() {
    Number* n = new Number;
    n->base = this;
    n->deduct = deduct + 1;
    n->repeat = return n;
  }
  void show() const {
    // show first Number
    show(deduct);
    // show the following one if any
    for (int i = 1; i < repeat; i++) {
      cout << str;
    }
    cout << endl;
  }

 private:
  void show(int deduct) const {
    // pass the deduct string
    cout << str;
  }

  Number* base;
  int repeat;
  int deduct;
  int base_length;
  string str;
};

int main() {
  Number n1{"123"};
  n1.show();
}