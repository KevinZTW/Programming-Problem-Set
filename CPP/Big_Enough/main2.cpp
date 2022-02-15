#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

const int MAX = 100000;
const int MAXBIT = 5;

class BigInt {
 public:
  long long operator[](int i) const { return m[i]; }
  long long &operator[](int i) { return m[i]; }
  BigInt() {
    l = 1, m[0] = 0;
    sign = 1;
  }
  friend istream &operator>>(istream &, BigInt &);
  friend ostream &operator<<(ostream &, BigInt);
  BigInt operator+(const BigInt &y);
  BigInt operator-(const BigInt &y);

 private:
  long long m[1000];
  int l;
  int sign;
};

istream &operator>>(istream &in, BigInt &y) {
  string num;
  in >> num;

  if (num[0] == -1)
    y.sign = -1, num = num.substr(1, num.size() - 1);
  else
    y.sign = 1;

  reverse(num.begin(), num.end());
  int id = 0;

  for (int i = 0; i < num.size(); i += MAXBIT) {
    string sub = num.substr(i, MAXBIT);
    reverse(sub.begin(), sub.end());
    y.m[id++] = stoi(sub);
  }
  y.l = id;
  return in;
}

ostream &operator<<(ostream &out, BigInt x) {
  if (x.sign < 0) out << -1;
}

int main() {}