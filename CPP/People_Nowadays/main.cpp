#include <iostream>
#include <set>
#include <string>
/*
name :
age :


find :
kill :
young :

*/
using namespace std;
class People {
 public:
  int age;
  string name;
  bool operator<(const People& y) const {
    if (age < y.age)
      return true;
    else if (age > y.age)
      return false;
    else if (name < y.name)
      return true;
    else
      return false;
  }
};

int main() {
  //   freopen("input.txt", "r", stdin);
  int n, age;
  string instruct, name;
  set<People> store;
  cin >> n;

  while (n--) {
    cin >> instruct;
    if (instruct == "born") {
      cin >> name >> age;
      store.insert(People{age, name});
    } else if (instruct == "find") {
      cin >> name >> age;
      auto it = store.find(People{age, name});
      if (it == store.end())
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else if (instruct == "young") {
      People res = *store.begin();
      cout << res.name << " " << res.age << endl;
    } else if (instruct == "kill") {
      cin >> name >> age;
      store.erase(People{age, name});
    }
  }
}
