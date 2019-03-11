#include <cassert>  // assert
#include <deque>    // deque
#include <iostream> // cout, endl
#include <vector>   // vector

using namespace std;

#define TEST1
#define TEST2
#define TEST3
#define TEST4
#define TEST5
#define TEST6
#define TEST7
#define TEST8

template <typename T, typename C = deque<T>>
class my_stack {
    private:
        C _c;

    public:
        friend bool operator == (const my_stack& lhs, const my_stack& rhs) {
            return lhs._c == rhs._c;
        }

        my_stack () = default;


        my_stack (const C& c): 
            _c (c) {}

        size_t size() const {
            return _c.size();
        }

        bool empty() const {
            return _c.empty();
        }

        void push(const T& t) {
            _c.push_back(t);
        }

        const T& top() const {
            return _c.back();
        }

        T& top() {
            return _c.back();
        }

        void pop() {
            _c.pop_back();
        }
};

#ifdef TEST1
void test1 () {
    my_stack<int> x;                  // default constructor
    assert(x.empty());
    assert(x.size() == 0);}
#endif

#ifdef TEST2
void test2 () {
    my_stack<int> x;
    x.push(2);
    x.push(3);
    x.push(4);
    assert(!x.empty());
    assert(x.size() == 3);
    assert(x.top()  == 4);}
#endif

#ifdef TEST3
void test3 () {
    my_stack<int> x;
    x.push(2);
    x.push(3);
    x.push(4);
    x.pop();
    assert(x.size() == 2);
    assert(x.top()  == 3);}
#endif

#ifdef TEST4
void test4 () {
    my_stack<int> x;
    x.push(2);
    x.push(3);
    x.push(4);
    x.top() = 5;
    assert(x.top() == 5);
    const my_stack<int>& r = x;
//  r.top() = 6;
    assert(r.top() == 5);}
#endif

#ifdef TEST5
void test5 () {
    my_stack<int> x;
    x.push(2);
    x.push(3);
    x.push(4);
    my_stack<int> y = x;              // copy     constructor
    assert(x == y);}                  // equality operator
#endif

#ifdef TEST6
void test6 () {
    my_stack<int> x;
    x.push(2);
    x.push(3);
    x.push(4);
    my_stack<int> y;
    x.push(5);
    x.push(6);
    my_stack<int>& z = (x = y);       // copy assignment operator
    assert(x  == y);
    assert(&x == &z);}
#endif

#ifdef TEST7
void test7 () {
    my_stack<int, vector<int>> x;     // backing-container type
    x.push(2);
    x.push(3);
    x.push(4);
    x.pop();
    assert(x.size() == 2);
    assert(x.top()  == 3);}
#endif

#ifdef TEST8
void test8 () {
    vector<int> c;
    my_stack<int, vector<int>> x(c);  // container constructor
    x.push(2);
    x.push(3);
    x.push(4);
    x.pop();
    assert(x.size() == 2);
    assert(x.top()  == 3);}
#endif

int main () {
    cout << "Stack.c++" << endl;
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

        #ifdef TEST7
        case 7:
            test7();
            break;
        #endif

        #ifdef TEST8
        case 8:
            test8();
            break;
        #endif

        default:
            assert(false);}
    cout << "Done." << endl;
    return 0;}