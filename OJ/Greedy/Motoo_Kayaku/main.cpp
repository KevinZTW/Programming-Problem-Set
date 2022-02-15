#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define ll long long int
using namespace std;

ll n, x, A, B, M, num;
vector<pair<int, ll>> v;
vector<ll> prefix;

bool cmp(const pair<int, ll> a, const pair<int, ll> b) {
  return a.second < b.second;
}

bool cmp_index(const pair<int, ll> a, const pair<int, ll> b) {
  return a.first < b.first;
}

int upper_bound(ll m) {
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    //表示通通加到 a_mid 所需要的點數
    ll ans = ((ll)(mid + 1) * v[mid].second) - prefix[mid];
    if (ans > m)
      r = mid;
    else
      l = mid + 1;
  }
  return r;
}

int main() {
  //   freopen("input.txt", "r", stdin);

  cin >> n >> x >> A >> B >> M;
  for (int i = 0; i < n; i++) {
    cin >> num;
    v.push_back({i, num});
  }

  // sort v
  sort(v.begin(), v.end(), cmp);

  prefix = vector<ll>(n);

  for (int i = 0; i < n; i++) {
    if (i == 0)
      prefix[i] = v[i].second;
    else
      prefix[i] = prefix[i - 1] + v[i].second;
  }

  ll max_ans = 0;
  vector<pair<int, ll>> ans_v = v;
  int min_ai = 0;
  int ans_i = n;

  // assume x is too big and there's no ai close to it
  // we should only use skill point to raise the minumum
  int min_index = upper_bound(M) - 1;
  ll need = ((ll)(min_index + 1) * v[min_index].second) - prefix[min_index];
  ll left = M - need;
  ll minimum = min(v[min_index].second + (left / (ll)(min_index + 1)), x);
  max_ans = minimum * B;
  min_ai = minimum;

  // have at least one ai can add to target x
  for (int i = n - 1; i >= 0; i--) {
    M -= (x - v[i].second);
    if (M < 0) break;
    v[i].second = x;
    // handle the minumum part

    int min_index = upper_bound(M) - 1;
    //   cout << "min index: " << min_index << endl;
    ll need = ((ll)(min_index + 1) * v[min_index].second) - prefix[min_index];
    ll left = M - need;
    // need to notice the case when m >> x
    ll minimum = min(v[min_index].second + (left / (ll)(min_index + 1)), x);

    ll ans = (n - i) * A + minimum * B;

    if (ans > max_ans) {
      max_ans = ans;
      ans_i = i;
      min_ai = minimum;
    }
  }

  cout << max_ans << endl;

  for (int i = n - 1; i >= ans_i; i--) {
    ans_v[i].second = x;
  }

  for (auto &i : ans_v) {
    if (i.second > min_ai) break;
    i.second = min_ai;
  }

  sort(ans_v.begin(), ans_v.end(), cmp_index);
  for (auto it = ans_v.begin(); it != ans_v.end(); it++) {
    if (it == ans_v.end() - 1)
      cout << it->second;
    else
      cout << it->second << " ";
  }
}
