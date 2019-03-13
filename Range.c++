#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

#define TEST1
#define TEST2
#define TEST3
#define TEST4
#define TEST5

template <typename T>
class Range {

    private:
        T _begin;
        T _end;

    public:
        Range (T b, T e) :
            _begin (b),
            _end (e) 
        {}

        class iterator {

          // friend bool operator == (const iterator& lhs, const
          // iterator& rhs) {
          //     return lhs._t == rhs._t;
          // }

        private:
          T _t;

        public:
          iterator(T t) : _t(t) {}

          T operator*() const { return _t; }

          bool operator==(const iterator &v) const { return _t == v._t; }

          bool operator!=(const iterator &v) const {
            return !(_t == v._t);
          }

          iterator &operator++() {
            ++_t;
            return *this;
          }

          iterator operator++(int) {
            T v = _t;
            ++_t;
            return v;
          }

          iterator begin (Range r) {
              _t = r._begin;
              return this;
          }
        };

        iterator begin() const { return _begin; }

        iterator end() const { return _end; }
};

template <typename II1, typename II2>
bool my_equal (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

#ifdef TEST1
void test1 () {
    const Range<int> x(2, 2);
    const Range<int>::iterator b = begin(x);
    const Range<int>::iterator e = end(x);
    assert(b == e);}
#endif

#ifdef TEST2
void test2 () {
    Range<int> x(2, 3);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    assert(b != e);
    assert(2 == *b);
    Range<int>::iterator& y = ++b;
    assert(&y == &b);
    assert(b == e);}
#endif

#ifdef TEST3
void test3 () {
    Range<int> x(2, 4);
    Range<int>::iterator b = begin(x);
    Range<int>::iterator e = end(x);
    assert(b != e);
    assert(2 == *b);
    ++b;
    assert(b != e);
    assert(3 == *b);
    b++;
    assert(b == e);}
#endif

#ifdef TEST4
void test4 () {
    Range<int> x(2, 5);
    assert(my_equal(begin(x), end(x), begin({2, 3, 4})));}
#endif

#ifdef TEST5
void test5 () {
    Range<int> x(2, 5);
    int s = 0;
    for (int v : x)
        s += v;
    assert(s == 9);}
#endif

int main () {
    cout << "Range.c++" << endl;
    int n;
    cin >> n;
    switch (n) {
        #ifdef TEST1
        case 1:
            test1();
            break;
        #endif

        #ifdef TEST2
        case 2:
            test2();
            break;
        #endif

        #ifdef TEST3
        case 3:
            test3();
            break;
        #endif

        #ifdef TEST4
        case 4:
            test4();
            break;
        #endif

        #ifdef TEST5
        case 5:
            test5();
            break;
        #endif

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}