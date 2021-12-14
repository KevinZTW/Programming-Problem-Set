#include <iostream>
using namespace std;

class IntVec {
 public:
  IntVec();
  IntVec(size_t size, int default_value = 0)
      : size_{0},
        // what ??? static_cast<size_t>( ) compiler 叫我家的老師好像沒放
        capacity_{size * 2},
        elem_{new int[capacity_]} {
    for (int i = 0; i < size; ++i) {
      elem_[i] = default_value;
    }
  };
  IntVec(std::initializer_list<int> s);
  IntVec(const IntVec &v);  // copy constructor
  IntVec(IntVec &&v);       //兩個 && 來區別表示他是 move constructor
  void show() const {
    cout << "capacity : " << capacity_ << "size :" << size_ << endl;
    cout << "place on : " << elem_ << endl;
    for (int i = 0; i < size_; i++) {
      std::cout << elem_[i] << ",";
    }
    std::cout << endl;
  };
  size_t size() const { return size_; }
  IntVec &operator=(const IntVec &v);
  IntVec &operator=(IntVec &&v);
  ~IntVec() { delete[] elem_; }
  void push_back(int val) {
    if (size_ + 1 >= capacity_) {
      cout << "Not enough space!" << endl;
      IntVec u(size_, 0);
      for (int i = 0; i < size_; i++) {
        u.elem_[i] = elem_[i];
      }
      u.elem_[size_] = val;
      ++size_;
      capacity_ = u.capacity_;
      std::swap(elem_, u.elem_);
    }
    elem_[size_] = val;
    ++size_;
  }

 private:
  //注意順序!
  size_t size_;
  size_t capacity_;
  int *elem_;
};

IntVec::IntVec() : size_{0}, capacity_{100}, elem_{new int[capacity_]} {}
IntVec::IntVec(std::initializer_list<int> s) : size_{s.size()} {
  if (size_ * 2 > capacity_ * 2) {
    capacity_ = size_ * 2;
  } else {
    capacity_ = 100;
  }
  elem_ = new int[capacity_];
  if (s.size() > 0) {
    std::copy(s.begin(), s.end(), elem_);
  }
}
IntVec::IntVec(const IntVec &v)
    : size_{v.size_}, capacity_{v.capacity_}, elem_{new int[capacity_]} {
  cout << "copy constructor is called" << endl;
  for (int i = 0; i < v.size_; i++) {
    elem_[i] = v.elem_[i];
  }
}
//直接偷過來! 把人家清掉變成零 如果沒有的話會去用 copy 用了可以讓城市快一點
IntVec::IntVec(IntVec &&v)
    : size_{v.size_}, capacity_{v.capacity_}, elem_{v.elem_} {
  cout << "move constructor is called" << endl;
  v.elem_ = nullptr;
  v.capacity_ = 0;
  v.size_ = 0;
}
// copy assignment
IntVec &IntVec::operator=(const IntVec &v) {
  size_ = v.size_;
  capacity_ = v.capacity_;
  //老師說可以用底下 delete, new 但是我們可以少做一點這樣的操作
  IntVec u{v};
  std::swap(u.elem_, elem_);
  //   delete[] elem_;
  //   elem_ = new int[capacity_];
  for (int i = 0; i < size_; i++) {
    elem_[i] = v.elem_[i];
  }
  //回傳
  return *this;
}
// move assignment
IntVec &IntVec::operator=(IntVec &&v) {
  cout << "move assignemnt is called" << endl;
  if (this != &v) {
    delete[] elem_;  //把原本炸掉偷別人的

    elem_ = v.elem_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    v.elem_ = nullptr;  //沒寫這個會出問題 為什麼應該是因為我偷了臨時的 object
                        //的 _elem，結果還留了資料給他結果被回收掉了
    v.capacity_ = 0;
    v.size_ = 0;
  }
  return *this;
}
int main() {
  IntVec u{};
  IntVec v{1, 2, 3};
  IntVec w{v};  // copy constructor
  // IntVec z{IntVec{6, 6, 6}};  這邊裏面的臨時 object
  // 絕對不會被放到左邊，因此應該會呼叫...結果沒有 好像被 Initialize list 做掉了
  IntVec z{std::move(u)};
  u = IntVec{9, 2, 1};
  u.show();
  v.show();
  w.show();
  cout << "v size is : " << v.size() << endl;

  //想要把 w 複製給 v 的話就要實作複製的 operator，在實作之前可以看到 default
  //複製的行為是把 w 裏面的直原封不動的搬給 v 包含  size, capacity, elem* 16
  // byte 所以可以觀察到 elem 的 Pointer 位址是同一個，(同一個門牌號碼)
  u = (v = w);  // copy assignment
  for (int i = 0; i < 150; ++i) {
    v.push_back(i);
  }
  v.show();
}