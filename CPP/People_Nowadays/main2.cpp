#include <iostream>
#include <set>
#include <string>

using namespace std;
class People {
 public:
  bool operator<(const People& b) const {
    if (age < b.age)
      return true;
    else if (age > b.age)
      return false;
    else if (name < b.name)
      return true;
    else
      return false;
  }
  string name;
  int age;
};

int main() {
  //   freopen("input.txt", "r", stdin);
  int n;
  string instruct;
  set<People> pset;
  string name;
  int age;
  cin >> n;
  while (n--) {
    cin >> instruct;
    if (instruct == "born") {
      cin >> name >> age;
      pset.insert(People{name, age});
    } else if (instruct == "find") {
      cin >> name >> age;
      auto it = pset.find(People{name, age});
      if (it == pset.end())
        cout << "NO" << endl;
      else
        cout << "YES" << endl;
    } else if (instruct == "kill") {
      cin >> name >> age;
      pset.erase(People{name, age});
    } else if (instruct == "young") {
      auto it = pset.begin();
      if (it != pset.end()) cout << it->name << " " << it->age << endl;
    }
  }
}
