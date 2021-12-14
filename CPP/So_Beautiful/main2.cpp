#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, map<char, vector<string>>> diction;

int main() {
  //   freopen("input.txt", "r", stdin);
  int n;
  cin >> n;

  while (n--) {
    string str;
    cin >> str;
    int count = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
          str[i] == 'u') {
        count++;
      }
    }
    char str_end = str[str.length() - 1];
    diction[count][str_end].push_back(str);
  }

  int uncomp = 0, comp = 0;
  for (auto i : diction) {
    int tmp = 0;
    for (auto cstr : i.second) {
      int s = cstr.second.size();
      comp += s / 2;
      tmp += s % 2;
    }
    uncomp += tmp / 2;
  }
  int ans;
  if (comp > uncomp) {
    ans = uncomp + (comp - uncomp) / 2;
  } else {
    ans = comp;
  }

  cout << ans << endl;
}