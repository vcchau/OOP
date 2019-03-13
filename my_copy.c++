#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

#define TEST1
#define TEST2

template <typename T1, typename V>
V my_copy(T1 b, T1 e, V v) {
    while (b != e) {
        *v = *b;
        ++b;
        ++v;
    }
    return v;
}

#ifdef TEST1
void test1 () {
    const int a[]  = {2, 3, 4};
    int       b[5] = {};
    int*      p    = my_copy(a, a + 3, b + 1);
    assert(p == b + 4);
    assert(equal(b, b + 5, begin({0, 2, 3, 4, 0})));}
#endif

#ifdef TEST2
void test2 () {
    const list<int>       x = {2, 3, 4};
    vector<int>           y(5);
    vector<int>::iterator p = my_copy(begin(x), end(x), begin(y) + 1);
    assert(p == begin(y) + 4);
    assert(equal(begin(y), end(y), begin({0, 2, 3, 4, 0})));}
#endif

int main () {
    cout << "Copy.c++" << endl;
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

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}