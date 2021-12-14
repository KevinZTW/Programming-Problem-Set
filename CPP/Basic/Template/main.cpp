#include <iostream>
#include <memory>

using namespace std;
template <typename T>
class List {
 private:
  struct Node {
    Node(T v, const shared_ptr<const Node> &tail) : val{v}, next{tail} {}
    T val;
    shared_ptr<const Node> next;
  };
  shared_ptr<const Node> head;
  // 那今天我們想要禁止隱性轉換這種寫法的話隻需要在 MyInteger(int n)
  // 建構子前面加上 explicit 關鍵字，告訴編譯器隻能用顯性轉換
  explicit List(const shared_ptr<const Node> &nodes) : head{nodes} {}

 public:
  List() {}
  /* head{nullptr} done by shared_ptr 以前 c 指針不能不幫他設值 Node *n;
  printf(n->val) share pointer 要指的就要用 make_shared
  來產生，因為他會紀錄多少人指向他才知道如何做 gc 這也是為什麼都要寫
     constructor destructor*/
  List(T val, const List &tail) : head{make_shared<Node>(val, tail.head)} {}
  //老師說建構式一層一層包起來，永遠不會讓用戶接觸到底層？

  bool isEmpty() const { return (head == nullptr); }

  //取出 list 最前面元素
  T car() const {
    if (isEmpty()) exit(EXIT_FAILURE);
    return head->val;
  }
  //注意這邊是 return list 老師說
  List cdr() const {
    if (isEmpty()) exit(EXIT_FAILURE);
    //這邊我們沒有造出一個新的 List 只是把現在的下一個 Node 包裝成一個 List
    return List(head->next);
  }
  void show() const {
    if (isEmpty())
      std::cout << ".\n";
    else {
      std::cout << car() << "->";
      cdr().show();
    }
  }
};
/* 這邊 <typdename T> 表示以後要用的時候都要像是 :
    List mylist;
    cons<int>(3, mylist);
*/
template <typename T>
List<T> cons(T val, List<T> tail) {
  return List<T>{val, tail};
}

//原本是 T 會有一個 function 把List 裏面的 T 都轉換成 S typde
template <typename S, typename T, typename F>
List<S> mpal(F f, List<T> lst) {
  if (lst.isEmpty())
    return List<S>();
  else
    return List<S>(f(lst.car()), mapl<S>(f, lst.cdr()));
}

template <typename T, typename P>
List<T> filter(P p, List<T> lst) {
  if (lst.isEmpty()) return List<P>();
  if (p(lst.car()))
    return List<T>(lst.car(), filter(p, lst.cdr()));
  else
    return filter(p, lst.cdr());
}

int main() {
  cout << "hello" << endl;
  List<int> a;
  List<int> b(1, a);
  List<int> c(2, b);
  List<int> d(9, c);
  d.show();
}