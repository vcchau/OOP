
#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;


void pointers() {
  int i = 2;
  const int* p = &i;
  assert (*p == i);
  // Increment the pointer which changes the object p points to
  ++p;
  // assert (*p == i); This fails

  cout << *p << endl;

  int* const p1 = &i;
  int j = 3;
  // p1 = j;  This fails because we try to reassign p1 which is int* const
}

void lvalues() {
  int i = 1;
  int j = 2;
  int k = 69;

  (i += j) = k; // Equivalent to i = k

  cout << "I: " << i << " J: " << j << " K: " << k << endl;

  int a = 4;
  int b = 10;
  cout << a++ << endl;  // 4
  cout << ++b << endl;  // 11

  int c = 5;
  // cout << ++c++ << endl; doesn't compile error: lvalue required as increment operand
}

void reference() {
  int i = 3;
  // int* p = i;  Does not compile error: invalid conversion from ‘int’ to ‘int*’
  int* z = &i;  // z is an 'alias' for i;
  ++i;
  cout << "z : " << *z << " i: " << i << endl;  // *z = i because z is a pointer

  i = 54;
  cout << "z : " << *z << " i: " << i << endl;  // changing i changes z

  *z = 69;
  cout << "z : " << *z << " i: " << i << endl;  // vice versa changing z changes i; they are linked

  int a = 15;
  int&b = a;

  cout << "a: " << a << " b: " << b << endl;  // a and b are the same

  a = 69;
  cout << "a: " << a << " b: " << b << endl;  // changing one changes the other

  b = 30;
  cout << "a: " << a << " b: " << b << endl;
}

void arrays() {
  int a[4] = {1, 2, 3, 4};
  int* b = a;

  for (int i = 0; i < 4; ++i) {
    cout << a[i] << " ";
    a[i] = 0;         // changes b to {0, 0, 0, 0} because they point to the same thing
  }
  cout << endl;



  for (int i = 0; i < 4; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;

  int c[4] = {1, 2, 3, 4};
  int* d = c;

  for (int i = 0; i < 4; ++i) {
    cout << c[i] << " ";
  }
  cout << endl;

  // c = {5, 6, 7, 8, 9, 10};  doesn't compile error: assigning to an array from an initializer list
  c[0] = 5;
  c[1] = 6;
  c[2] = 7;
  c[3] = 8;
  // c[4] = 9;    will work but may cause errors
  // c[5] = 10;   causes d to represent 5, 6, 7, 8, 9, 10, 11
  // c[6] = 11;

  for (int i = 0; i < 7; ++i) {
    cout << d[i] << " ";
  }
  cout << endl;
}

void f (int p[]) {
    cout << sizeof(p) << " ";
    ++p;
    ++*p;
    p = 0;}

void test1 () {
    int a[] = {2, 3, 4};
    cout << sizeof(a) << " ";
    f(a);
    cout << a[0] << " ";
    cout << a[1] << " ";
    cout << a[2] << endl;}


void g (int* p) {
    cout << sizeof(p) << " ";
    ++p;
    ++*p;
    p = 0;}

void test2 () {
int a[] = {2, 3, 4};
cout << sizeof(a) << " ";
g(a);
cout << a[0] << " ";
cout << a[1] << " ";
cout << a[2] << endl;}

int main() {
  using namespace std;
  // pointers();
  // lvalues();
  // reference();
  // arrays();
  //test1();  // Quiz 11 -> 12 8 2 4 4
  //test2();    // Quiz 11 Q3 -> 12 8 2 4 4
}
