#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list

using namespace std;

#define TEST1
#define TEST2

template <typename T, typename V>
void my_fill(T start, T end, const V& value) {
    while (start != end) {
        *start = value;
        ++start;
    }
}

// template <typename FI, typename T> 
// void my_fill(FI b, FI e, const T &v) {
//   while (b != e) {
//     *b = v;
//     ++b;
//   }
// }

#ifdef TEST1
void test1 () {
    int a[5] = {};
    my_fill(a + 1, a + 4, 2);
    assert(equal(a, a + 5, begin({0, 2, 2, 2, 0})));}
#endif

#ifdef TEST2
void test2 () {
    list<int>           x(5);
    list<int>::iterator b = begin(x);
    list<int>::iterator e = end(x);
    ++b;
    --e;
    my_fill(b, e, 2);
    assert(equal(begin(x), end(x), begin({0, 2, 2, 2, 0})));}
#endif

int main () {
    cout << "Fill.c++" << endl;
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