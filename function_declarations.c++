
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <cmath>

using namespace std;

template <typename T>
T my_multiply_1 (const T& x, const T& y) {
  return x * y;
}

template <typename T>
struct my_multiply_2 {
  T operator () (const T& x, const T& y) const {
    return x * y;
  }
};

template <typename T>
class my_multiply_3 {
private:
  T _n;

public:
  my_multiply_3 (const T& n) :
    _n (n) {}

  T operator () (const T& x) const {
    return _n * x;
  }
};

template <typename I1, typename I2, typename F>
I2 my_transform (I1 b, I1 e, I2 cur, F f) {
  while (b != e) {
    *cur = f(*b);
    ++b;
    ++cur;
  }
  return cur;
}

int main() {
  const function<int (int, int)> f = my_multiply_1<int>;
  cout << "As a function: " << f(4, 5) << endl;

  const function<int (int, int)> g = my_multiply_2<int>();
  cout << "As a struct: " << g(4, 5) << endl;

  const function<int (int)> h = my_multiply_3<int>(5);
  cout << "As a class: " << h(4) << endl;

  cout << "Using transform: " << endl;
  const function<int (int)> j = my_multiply_3<int>(10);
  list<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list<int> res (10, 0);
  list<int> res1 (10, 0);

  transform(begin(num), end(num), begin(res), j);
  for (int i : res) {
    cout << i << " ";
  }
  cout << endl;

  my_transform(begin(num), end(num), begin(res1), j);
  for (int i : res1) {
    cout << i << " ";
  }
  cout << endl;

}
