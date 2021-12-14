#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, map<char, vector<string>>> diction;

int main() {
  freopen("input.txt", "r", stdin);

  int n;
  string str;

  cin >> n;

  while (n--) {
    cin >> str;
    int len = str.length();
    int vowel_num = 0;
    for (int i = 0; i < len; i++)
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' ||
          str[i] == 'u')
        vowel_num++;
    char end = str[len - 1];
    diction[vowel_num][end].push_back(str);
  }
  int comp = 0, uncomp = 0;
  for (auto i : diction) {
    int tmp = 0;
    for (auto v : i.second) {
      int s = v.second.size();
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
