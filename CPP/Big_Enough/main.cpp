#include <iostream>
#include <string>
using namespace std;
const int MAX = 100000;
const int MAXBIT = 5;
const int MAXN = 1000;

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

istream &operator>>(istream &in, BigInt &b) {
  // 25316524
  string num;
  in >> num;

  if (num[0] == '-')
    num = num.substr(1, num.length() - 1), b.sign = -1;
  else
    b.sign = 1;

  reverse(num.begin(), num.end());
  int id = 0;
  for (int i = 0; i < num.length(); i += MAXBIT) {
    string sub = num.substr(i, 5);
    reverse(sub.begin(), sub.end());
    b.m[id++] = stoi(sub);
  }
  b.l = id;
  return in;
}

ostream &operator<<(ostream &out, BigInt b) {
  if (b.sign == -1) out << '-';
  out << b.m[b.l - 1];
  for (int i = b.l - 2; i >= 0; i--) {
    out.width(MAXBIT);
    out.fill('0');
    out << b.m[i];
  }
  return out;
}

int main() {
  freopen("input.txt", "r", stdin);
  BigInt x, y;
  while (cin >> x >> y) {
    cout << x << " " << y << endl;
  }
}