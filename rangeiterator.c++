#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

#define TEST1
#define TEST2
#define TEST3
#define TEST4
#define TEST5

template <typename T>
class RangeIterator {

    // friend bool operator == (const RangeIterator& lhs, const RangeIterator& rhs) {
    //     return lhs._t == rhs._t;
    // }

    private:
        T _t;

    public:

        RangeIterator (T t):
            _t (t) {}

        T operator * () const {
            return _t;
        }

        bool operator == (const RangeIterator& v) const {
            return _t == v._t;
        }

        bool operator != (const RangeIterator& v) const {
            return !(_t == v._t);
        }

        RangeIterator& operator ++ () {
            ++_t;
            return *this;
        }

        RangeIterator operator ++ (int) {
            T v = _t;
            ++_t;
            return v;
        }

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
    const RangeIterator<int> b = 2;
    assert(*b == 2);}
#endif

#ifdef TEST2
void test2 () {
    const RangeIterator<int> b = 2;
    const RangeIterator<int> e = 2;
    assert(b == e);}
#endif

#ifdef TEST3
void test3 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 3;
    assert(b  != e);
    assert(*b == 2);
    RangeIterator<int>& x = ++b;
    assert(&x == &b);
    assert(b  == e);}
#endif

#ifdef TEST4
void test4 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 4;
    assert(b  != e);
    assert(*b == 2);
    ++b;
    assert(b  != e);
    assert(*b == 3);
    RangeIterator<int> x = b++;
    assert(&x != &b);
    assert(b  == e);}
#endif

#ifdef TEST5
void test5 () {
    RangeIterator<int> b = 2;
    RangeIterator<int> e = 5;
    assert(my_equal(b, e, begin({2, 3, 4})));}
#endif

int main () {
    cout << "RangeIterator.c++" << endl;
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