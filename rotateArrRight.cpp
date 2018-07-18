/*Description of problem:
Given a linked list, rotate the list to the right by k places, where k is non-negative.
*/

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
  if(!head || k == 0) return head;

  ListNode* cur = head;
  int size = 1;
  while(cur->next) {
      size++;
      cur = cur->next;
  }
  if((k%size == 0 && k != 1) || size ==1)
      return head;
  cur->next = head;
  k = k%size;
  int pos = size - k - 1;
  cur = head;
  while(pos) {
      cur = cur->next;
      pos--;
  }
  head = cur->next;
  cur->next = NULL;

  return head;
}
void printList(ListNode* head) {
  if(!head) {
    cout << "Empty list." << endl;
    return;
  }
  ListNode* iter = head;
  while(iter) {
    cout << iter->val << " ";
    iter = iter->next;
  }
  cout << endl;
}

int main() {
  ListNode* t0 = NULL;
  t0 = rotateRight(t0, 3);
  printList(t0);

  ListNode* t1 = new ListNode(1);
  t1 = rotateRight(t1, 3);
  printList(t1);

  ListNode* t2 = new ListNode(1);
  t2->next = new ListNode(2);
  t2 = rotateRight(t2, 1);
  printList(t2);


  ListNode* t3 = new ListNode(1);
  t3->next = new ListNode(1);
  t3 = rotateRight(t3, 4);
  printList(t3);

  ListNode* t4 = new ListNode(1);
  t4->next = new ListNode(2);
  t4->next->next = new ListNode(2);
  t4->next->next->next = new ListNode(4);
  t4 = rotateRight(t4, 3);
  printList(t4);


  ListNode* t5 = new ListNode(1);
  t5->next = new ListNode(2);
  t5->next->next = new ListNode(3);
  t5->next->next->next = new ListNode(4);
  t5 = rotateRight(t5, 4);
  printList(t5);


  ListNode* t6 = new ListNode(0);
  t6->next = new ListNode(2);
  t6->next->next = new ListNode(4);
  t6->next->next->next = new ListNode(3);
  t6->next->next->next->next = new ListNode(4);
  t6 = rotateRight(t6, 0);
  printList(t6);

  ListNode* t7 = new ListNode(1);
  t7->next = new ListNode(2);
  t7->next->next = new ListNode(2);
  t7->next->next->next = new ListNode(2);
  t7->next->next->next->next = new ListNode(4);
  t7->next->next->next->next->next = new ListNode(1);
  t7->next->next->next->next->next->next = new ListNode(3);
  t7->next->next->next->next->next->next->next = new ListNode(3);
  t7->next->next->next->next->next->next->next->next = new ListNode(1);
  t7 = rotateRight(t7, 27);
  printList(t7);

  return 0;
}
