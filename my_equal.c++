#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list
#include <vector>    // vector

using namespace std;

#define TEST1
#define TEST2
#define TEST3
#define TEST4

template <typename T1, typename T2>
bool my_equal(T1 i1, T1 i2, T2 j1) {
    while (i1 != i2) {
        if (*i1 != *j1) {
            return false;
        }
        ++i1;
        ++j1;
    }
    return true;
}

#ifdef TEST1
void test1 () {
    const int a[] = {2, 3, 4};
    const int b[] = {0, 2, 3, 4, 0};
    assert(!my_equal(a, a + 3, b));}
#endif

#ifdef TEST2
void test2 () {
    const int  a[] = {2, 3, 4};
    const long b[] = {0, 2, 3, 4, 0};
    assert(my_equal(a, a + 3, b + 1));}
#endif

#ifdef TEST3
void test3 () {
    const list<int> x = {2, 3, 4};
    const list<int> y = {0, 2, 3, 4, 0};
    assert(!my_equal(begin(x), end(x), begin(y)));}
#endif

#ifdef TEST4
void test4 () {
    const list<int>   x = {2, 3, 4};
    const vector<int> y = {0, 2, 3, 4, 0};
    assert(my_equal(begin(x), end(x), begin(y) + 1));}
#endif

int main () {
    cout << "Equal.c++" << endl;
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

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}my
