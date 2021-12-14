#include <iostream>
#include <set>

using namespace std;
class Job {
 public:
  int start;
  int finish;
  Job(int s, int f) : start(s), finish(f) {}
  bool operator<(const Job& j) const {
    if (finish < j.finish) return true;
    return false;
  }
};

void DP(set<Job> jobs) {
  jobs.insert(Job(0, 0));
  //改了下面的 start
  jobs.insert(Job((int)(2e6), (int)(2e6)));

  int l = jobs.size();
  int n = l - 1;
  int A[l + 1][l + 1];

  /* Aij is 0 for i>=j, because if there's ak in Aij,  fi <= sk <fk <= sj < fj
   => fi < fj (contradiction)*/

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++) {
      if (i >= j || (j - i) == 1) A[i][j] = 0;
    }
  }
  //??
  A[l][l] = 0;
  /* Aij = Aik + ak + Akj
   A prefix approach start form A00, A01....Al-1l-1 */

  // my first approach is instinctly loop i 0-l-1; j 0-l-1 but it failed since
  // it would require data I havent counted yet
  // for (int i = 0; i < l - 1; i++) {
  //   for (int j = 0; j < l - 1; j++) {
  //     int max = 0;
  //     for (int k = i + 1; k < j; k++) {
  //       int n = A[i][k] + A[k][j] + 1;
  //       if (n > max) max = n;
  //     }
  //     A[i][j] = max;
  //   }
  // }
  for (int L = 2; L <= l; L++) {
    for (int i = 0; i <= l - L; i++) {
      int j = i + L;
      int max = 0;
      for (int k = i + 1; k < j; k++) {
        cout << "i: " << i << "j: " << j << "k: " << k << endl;
        Job ai = *next(jobs.begin(), i);
        Job ak = *next(jobs.begin(), k);
        Job aj = *next(jobs.begin(), j);
        cout << "ai f: " << ai.finish;
        cout << "ak s: " << ak.start;
        cout << "ak f: " << ak.finish;
        cout << "aj s: " << aj.start;
        cout << endl;
        if (ak.start >= ai.finish && ak.finish <= aj.start) {
          int n = A[i][k] + A[k][j] + 1;
          if (n > max) max = n;
        }
      }
      A[i][j] = max;
    }
  }
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < l; j++) {
      cout << A[i][j] << ", ";
    }
    cout << endl;
  }
  cout << A[0][l - 1] << endl;
}

void Greedy(set<Job> jobs, set<Job>& selected) {
  // pick the first one
  auto it = next(jobs.begin(), 0);
  selected.insert(*it);

  Job latest = *it;
  for (auto it = next(jobs.begin(), 1); it != jobs.end(); it++) {
    // cout << "latest f: " << latest.finish << it->start << " " << it->finish
    // << endl;
    if (it->start >= latest.finish) {
      selected.insert(*it);
      latest = *it;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  int n, s, f;
  set<Job> jobs, selected;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s >> f;
    jobs.insert(Job(s, f));
  }

  DP(jobs);
  Greedy(jobs, selected);

  for (auto it = selected.begin(); it != selected.end(); it++) {
    cout << "[s: " << it->start << "f: " << it->finish << "]" << endl;
  }
  //   cout << next(jobs.begin(), 0)->finish << endl;
}