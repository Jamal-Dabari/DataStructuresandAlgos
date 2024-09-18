#include <iostream>
using namespace std;

struct ListNode {
  int value;
  ListNode *next;
};

void printNode(ListNode *);

int lengthList(ListNode *);

int main() {

  ListNode *a = new ListNode;
  ListNode *b = new ListNode;
  ListNode *c = new ListNode;

  a->value = 3;
  b->value = 8;
  c->value = 10;

  a->next = b;
  b->next = c;
  c->next = NULL;

  printNode(a);
  cout << endl;
  cout << "the total number of nodes in the list is " << lengthList(a) << endl;
}

void printNode(ListNode *head) {
  cout << "Now, ";
  while (head != NULL) {
    cout << head->value << ", ";
    head = head->next;
  }
  cout << "are in the list";
}

int lengthList(ListNode *head) {

  int length = 0;
  while (head != NULL) {
    length++;
    head = head->next;
  }
  return length;
}
