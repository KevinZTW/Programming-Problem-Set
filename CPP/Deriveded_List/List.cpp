#include <cstdlib>
#include <iostream>
#include <memory>
using namespace std;
template <typename T>
class List {
 private:
  struct Node {
    Node(T v, const shared_ptr<const Node>& tail) : val{v}, next{tail} {}
    T val;
    shared_ptr<const Node> next;
  };
  shared_ptr<const Node> head;
  explicit List(const shared_ptr<const Node>& nodes) : head{nodes} {}

 public:
  List() {}  // head{nullptr} done by shared_ptr
  List(T val, const List& tail) : head{make_shared<Node>(val, tail.head)} {}
  bool isEmpty() const { return (head == nullptr); }
  T car() const {
    if (isEmpty()) exit(EXIT_FAILURE);
    return head->val;
  }
  List cdr() const {
    if (isEmpty()) exit(EXIT_FAILURE);
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
template <typename T>
List<T> cons(T val, List<T> tail) {
  return List<T>{val, tail};
}
template <typename S, typename T, typename F>
List<S> mapl(F f, List<T> lst) {
  if (lst.isEmpty())
    return List<S>();
  else
    return List<S>(f(lst.car()), mapl<S>(f, lst.cdr()));
}
template <typename T, typename P>
List<T> filter(P p, List<T> lst) {
  if (lst.isEmpty()) return List<T>();
  if (p(lst.car()))
    return List<T>(lst.car(), filter(p, lst.cdr()));
  else
    return filter(p, lst.cdr());
}
template <typename S, typename T, typename F>
S foldr(F f, S accumul, List<T> lst) {
  if (lst.isEmpty())
    return accumul;
  else
    return f(lst.car(), foldr(f, accumul, lst.cdr()));
}
template <typename S, typename T, typename F>
S foldl(F f, S accumul, List<T> lst) {
  if (lst.isEmpty())
    return accumul;
  else
    return foldl(f, f(accumul, lst.car()), lst.cdr());
}
template <typename T, typename F>
void foreach (F f, List<T> lst) {
  if (!lst.isEmpty()) {
    f(lst.car());
    foreach (f, lst.cdr())
      ;
  }
}
template <class T>
void print(List<T> lst) {
  foreach ([](T v) { cout << v << "->"; }, lst)
    ;
  cout << ".";
}
template <typename T>
List<T> concat(const List<T> a, const List<T> b) {
  if (a.isEmpty()) return b;
  return List<T>(a.car(), concat(a.cdr(), b));
}
template <typename T>
T findmax(const List<T> a) {
  return foldl([](T acc, T x) { return (acc > x) ? acc : x; }, a.car(), a);
}
List<int> qqsort(const List<int> a) {
  if (a.isEmpty()) return a;
  int piv = a.car();
  List<int> le = qqsort(filter<int>([=](int x) { return piv > x; }, a.cdr()));
  List<int> ri = qqsort(filter<int>([=](int x) { return piv <= x; }, a.cdr()));
  return concat<int>(le, cons(piv, ri));
}

int main() {
  List<int> l;
  List<int> n = cons(4, cons(5, cons(6, cons(7, cons<int>(8, l)))));
  l.show();
  n.show();
  auto m0 = mapl<double>([](int i) { return i * 0.5; }, n);  // List<double>
  m0.show();
  auto m = mapl<int>([](int i) { return i; }, n);  // List<int>
  m.show();
  m = filter<int>([](int i) { return i % 2 == 0; }, n);
  m.show();
  cout << foldl([](int acc, int i) { return acc + i; }, 0, m) << endl;
  print(m);  // or print<int>(m);
  cout << endl;
  List<List<int>> ll;
  auto mm = cons(m, cons(n, ll));  // List<List<int>>

  foreach (
      [](List<int> l) {
        cout << "[";
        print(l);
        cout << "]"
             << "->";
      },
      mm)
    ;
  cout << endl;
  auto g = concat(n, m);  // List<int>
  g.show();
  cout << findmax(g) << endl;
  List<int> ns =
      cons(9, cons(10, cons(6, cons(5, cons(4, cons(8, cons(7, l)))))));
  cout << "Before: ";
  ns.show();
  ns = qqsort(ns);
  cout << "After: ";
  ns.show();
}