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
BigInt BigInt::operator+(const BigInt &y) {
  // add y onto current object
  BigInt x(*this);
  int i;
  long long h;
  for (h = 0, i = 0; i < x.l || i < y.l || h; i++) {
    h += (i < x.l) * x[i] * x.sign + (i < y.l) * y[i] * y.sign;
    x[i] = h % MAX;
    h / MAX;
  }

  //現在每一位數都可能有 negative
  x.l = i;

  // decrease x.l to clean up space with 0 value (if x, y has many block addup
  // with 0)
  // need to consider situation when x = 0
  for (; x.l > 1 && x[x.l - 1] == 0; x.l--)
    ;

  x.sign = (x[x.l - 1] >= 0) ? 1 : -1;
  if (x[x.l - 1] >= 0) {
    //如果最高項次是正的或是 0 底下小於 0 儘管借位 一路處理到最高位!
    for (i = 0; i < x.l; i++) {
      if (x[i] < 0) {
        x[i] += MAX;
        x[i + 1] -= 1;
      }
    }
  } else {
    //如果最高項次是負數 底下是正的借位
    for (i = 0; i < x.l; i++) {
      if (x[i] > 0) {
        x[i + 1]++;
        x[i] -= MAX;
      }
    }
  }
  //全部乘以 x 的..
  for (i = 0; i < x.l; i++) x[i] *= x.sign;
  //再檢查一次有沒有被扣成 0 的狀況!
  for (; x.l > 1 && x[x.l - 1] == 0; x.l--)
    ;
  //處理 sign 是負數但是 x = 0 的情況
  if (x.sign == -1 && x.l == 1 && x[0] == 0) x.sign = 1;
  return x;
}

istream &operator>>(istream &in, BigInt &b) {
  // 12341234
  string num;
  in >> num;

  if (num[0] == '-')
    num = num.substr(1, num.length() - 1), b.sign = -1;
  else
    b.sign = 1;

  reverse(num.begin(), num.end());
  // 43214321
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
  // the leftmost string no need to add padding
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