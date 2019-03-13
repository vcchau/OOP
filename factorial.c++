#include <cassert>    // assert
#include <iostream>   // cout, endl

using namespace std;

// define it recursively
// define it iteratively

#define TEST1
#define TEST2
#define TEST3
#define TEST4
#define TEST5
#define TEST6

// int factorial(int v) {
//     int n = 1;
//     while (v > 1) {
//         n *= v--;
//     }
//     return n;
// }

int factorial(int v) {
    if (v > 1)
        return v * factorial(v - 1);
    else 
        return 1;
}

#ifdef TEST1
void test1 () {
    assert(factorial(0) == 1);}
#endif

#ifdef TEST2
void test2 () {
    assert(factorial(1) == 1);}
#endif

#ifdef TEST3
void test3 () {
    assert(factorial(2) == 2);}
#endif

#ifdef TEST4
void test4 () {
    assert(factorial(3) == 6);}
#endif

#ifdef TEST5
void test5 () {
    assert(factorial(4) == 24);}
#endif

#ifdef TEST6
void test6 () {
    assert(factorial(5) == 120);}
#endif

int main () {
    cout << "Factorial.c++" << endl;
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

        #ifdef TEST6
        case 6:
            test6();
            break;
        #endif

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}