#include <math.h>

#include <iostream>
#include <vector>

class CatToast {
 public:
  CatToast(int x, int y) : vx(x), vy(y), black_hole_no(0) {}

  int vx;
  int vy;
  int black_hole_no;

  friend float get_distance(CatToast &a, CatToast &b);
};

float get_distance(CatToast &a, CatToast &b) {
  return ((a.vx - b.vx) * (a.vx - b.vx) + (a.vy - b.vy) * (a.vy - b.vy));
}

// void dfs(std::vector<CatToast> list) { for () }

int main() {
  freopen("input.txt", "r", stdin);
  float n, r;
  int total_collided = 0;
  std::cin >> n >> r;

  std::vector<CatToast> cat_list;
  int black_hole_no = 0;

  for (int i = 0; i < n; i++) {
    int x, y;

    std::cin >> x >> y;
    CatToast tmp{x, y};
    // std::cout << "cat : " << x << y << std::endl;
    for (auto it = cat_list.begin(); it != cat_list.end(); it++) {
      if (get_distance(tmp, *it) <= r * r) {
        if (tmp.black_hole_no == 0 && it->black_hole_no == 0) {
          // std::cout << "1" << std::endl;
          black_hole_no++;
          total_collided += 2;
          tmp.black_hole_no = black_hole_no;
          it->black_hole_no = black_hole_no;
        } else if (tmp.black_hole_no == 0) {
          // std::cout << "2" << std::endl;
          tmp.black_hole_no = it->black_hole_no;
          total_collided += 1;
        } else {
          // std::cout << "3" << std::endl;
          it->black_hole_no = tmp.black_hole_no;
          // total_collided += 1;
        }
      }
    }
    cat_list.insert(cat_list.begin(), tmp);
  }
  // std::cout << "totoal colliede : " << total_collided << std::endl;
  std::cout << n - total_collided << " " << black_hole_no << std::endl;
}