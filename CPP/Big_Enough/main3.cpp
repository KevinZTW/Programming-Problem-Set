#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
const int MAXBIT = 5;
const int MAXN = 100000;
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

BigInt BigInt::operator+(const BigInt &y) {
  BigInt x(*this);
  int h, l;
  for (h = 0, l = 0; l < x.l || l < y.l || h; l++) {
    h += (x.l < l) * (x.sign) * x.m[l] + (y.l < l) * (y.sign) * y.m[l];
    x.m[l] = h % MAXN;
    h /= MAXN;
  }
  x.l = l;
  if (x.m[l - 1] < 0)
    x.sign = -1;
  else
    x.sign = 1;
  //如果一堆零
  for (; x.l > 1 && x.m[x.l - 1] == 0; x.l--)
    ;
  //如果是正的但下面有負數
  if (x.sign == 1) {
    for (int i = 0; i < l; i++) {
      if (x.m[i] < 0) {
        x.m[i] += MAXN;
        x.m[i - 1] -= 1;
      }
    }
  } else {
    for (int i = 0; i < l; i++) {
      if (x.m[i] > 0) {
        x.m[i] -= MAXN;
        x.m[i - 1]++;
      }
    }
  }
  for (int i = 0; i < x.l; i++) x.m[i] *= x.sign;
  for (; x.l > 1 && x.m[x.l - 1] == 0; x.l--)
    ;
  if (x.sign == -1 && x.l == 1 && x.m[0] == 0) x.sign = 1;
  return x;
}

istream &operator>>(istream &in, BigInt &y) {
  string num;
  in >> num;
  if (num[0] == '-') {
    y.sign = -1;
    num = num.substr(1, num.length() - 1);
  } else {
    y.sign = 1;
  }
  reverse(num.begin(), num.end());
  int id = 0;
  for (int i = 0; i < num.length(); i += MAXBIT) {
    string str = num.substr(i, MAXBIT);
    reverse(str.begin(), str.end());
    y.m[id++] = stoi(str);
  }
  y.l = id;
  return in;
}

ostream &operator<<(ostream &out, BigInt y) {
  if (y.sign == -1) out << "-";
  out << y.m[y.l - 1];
  for (int i = y.l - 2; i >= 0; i--) {
    out.width(5);
    out.fill('0');
    out << y.m[i];
  }
  return out;
}

int main() {
  freopen("input.txt", "r", stdin);

  BigInt x, y;
  while (cin >> x >> y) {
    cout << x << " " << y << endl;
    cout << x + y << endl;
  }
}