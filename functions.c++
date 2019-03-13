
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <list>
#include <cmath>

using namespace std;


template <typename T>
class my_multiply {
private:
  T _n;

public:
  my_multiply (const T& n) :
    _n (n) {}

  T operator () (const T& x) const {
    return _n * x;
  }
};

template <typename I1, typename I2, typename F>
I2 my_transform(I1 b, I1 e, I2 cur, F f) {
  while (b != e) {
    *cur = f(*b);
    ++b;
    ++cur;
  }
  return cur;
}

template <typename T>
T my_add (const T& x, const T& y) {
  return x + y;
}

void functions() {
  const function<int (int)> f = my_multiply<int>(3);
  int nums[] = {1, 2, 3, 4, 5};
  int res[5] = {};
  for (int i = 0; i < 5; ++i) {
    res[i] = f(nums[i]);
    cout << res[i] << " ";
  }
  cout << endl;

  list<int> nums1 = {1, 2, 3, 4, 5};
  list<int> res1(5, 0);
  my_transform(begin(nums1), end(nums1), begin(res1), f);

  for (int n : res1) {
    cout << n << " ";
  }
  cout << endl;

}

void functions1() {
  const function<int (int, int)> f = my_add<int>;
  cout << my_add(5, 6) << endl;
}


int main() {
  // functions();
  functions1();
}
