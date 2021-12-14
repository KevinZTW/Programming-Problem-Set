#include <iostream>

#include "dish.hpp"

Dish::~Dish() { free(food); }
std::istream &operator>>(std::istream &in, Dish &d) {
  std::string name;
  in >> name;
  if (name == "Ramsay") {
    int intel;
    in >> intel;
    auto f = new IdiotSandwich(intel);
    d.food = f;
  } else {
    auto s = new NormalSandwich(name);
    d.food = s;
  }
  return in;
}

void IdiotSandwich::print(std::ostream &out) {
  out << "An idiot sandwich with intelligence level " << this->getINT()
      << " only.";
}

void NormalSandwich::print(std::ostream &out) {
  out << this->getName() << ". Masterpiece of sandwiches.";
}
//===============
int n;
Dish dish;

int main() {
  freopen("input.txt", "r", stdin);
  std::cin >> n;
  while (n--) {
    std::cin >> dish;
    std::cout << dish.getFood() << std::endl;
  }
  return 0;
}
