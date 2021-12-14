#include <sys/time.h>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define ll long long int

using namespace std;
using namespace std::chrono;

ll year = 31556952000;
ll month = 2592000000;
ll day = 24 * 60 * 60 * 1000;
ll hour = 60 * 60 * 1000;
ll minute = 60 * 1000;

class Date {
  // constructor
 private:
  long long int _millisecond;
  // 1/1000 second
 public:
  Date(long long int now) : _millisecond{now} {}
  Date() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    _millisecond = tp.tv_sec * 1000 + tp.tv_usec / 1000;
  }
  Date &operator+=(Date x) {
    _millisecond += x._millisecond;
    return *this;
  }
  Date &operator-=(Date x) {
    _millisecond -= x._millisecond;
    return *this;
  }
  ll now() { return _millisecond; }
  string toDuration() { return to_string(_millisecond / hour) + " hours"; }
  string toDate() {
    // 1930 Jan 1

    int y = _millisecond / year;
    int m = (_millisecond - y * year) / month;
    int d = (_millisecond - y * year - m * month) / day;

    return to_string(1970 + y) + "y " + to_string(1 + m) + "m " + to_string(d) +
           "d";
  }
};

void changeName(const std::vector<std::string> &names) {
  for (auto i : names) {
    i = "haha";
  }
  // change name
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void printModified(function<int(int)> f, int x) {
  int res = f(x);
  cout << res << endl;
}

int &max(int &a, int &b) { return (a > b) ? a : b; }
int main() {
  std::cout << "hello world  ";

  std::vector<int> w{1, 2, 3, 4};
  std::vector<std::string> names{"kevin", "kelly", "kelly"};
  changeName(names);

  for (auto i : names) {
    std::cout << i << std::endl;
  }

  int x = 3, y = 5;
  max(x, y) = 0;

  swap(x, y);
  cout << "x:" << x << "y:" << y << endl;

  vector<int> v;
  for (auto i = 0; i < 10; i++) v.push_back(i * 5);

  // v.begin 會得到開頭的指標
  // lamda function
  for_each(v.begin(), v.end(), [](int &n) {
    if (n % 2 == 0) cout << "is even\n";
    n = n + 1;
  });
  for (auto i : v) {
    cout << setw(3) << i;
  }
  cout << "\n";

  printModified([](int n) { return n * 2; }, 2);
  // printf("%d", chrono::system_clock::now());
  Date now;
  ll nextDay = 1636806093562 + day;
  Date tomorrow(nextDay);

  cout << now.toDate() << endl;
  cout << now.now();
}
