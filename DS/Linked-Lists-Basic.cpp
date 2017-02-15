#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

int main() {
  node *n;
  node *t;
  node *h;

  n = new node;
  n->data = 1;
  t = n;
  h = n;
  cout << h->data << endl;

  n = new node;
  n->data = 2;
  t->next = n;
  t = t->next;
  cout << t->data << endl;

  n = new node;
  n->data = 3;
  t->next = n;
  cout << h->next->next->data << endl;

  return 0;
}

/*
output:
1
2
3
 */
