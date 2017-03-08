#include <iostream>

using namespace std;

int main() {

  int num = 7;
  int *ppp = &num; // int *ppp; ppp = &num; // same

  cout << "int num = 7;" << endl;
  cout << "int *ppp;\nppp = &num;" << endl;
  cout << "-----------------" << endl;
  cout << "num=" << num << endl;
  cout << "*ppp=" << *ppp << endl;
  cout << "Address of num " << &num << endl;
  cout << "ppp=" << ppp << endl;
  cout << "Address of ppp " << &ppp << endl;

  return 0;
}

/*
output:
int num = 7;
int *ppp;
ppp = &num;
-----------------
num=7
*ppp=7
Address of num 0x7fff520197d8
ppp=0x7fff520197d8
Address of ppp 0x7fff520197d0
 */
