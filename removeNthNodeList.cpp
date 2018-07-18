/*Description of problem:
Given a linked list, remove the n-th node from the end of list and return its head.
Try to do it in one pass.
*/

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* ref=head, *main=head;
  int pos = n;
  while(pos) {
    ref = ref->next;
    pos--;
  }

  while(ref != NULL && ref->next != NULL) {
    main = main->next;
    ref = ref->next;
  }

  if(ref == NULL) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }

  else if(ref->next == NULL) {
    ListNode* temp = main->next;
    main->next = temp->next;
    delete temp;
  }

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

ListNode* createList(int num) {
  if(num == 0)
    return NULL;
  ListNode* head = new ListNode(1);
  ListNode* iter = head;
  for(int i = 2; i <= num; i++) {
    iter->next = new ListNode(i);
    iter = iter->next;
  }
  return head;
}


int main() {
  ListNode* t1 = createList(1);
  t1 = removeNthFromEnd(t1, 1);
  printList(t1);

  ListNode* t2 = createList(2);
  t2 = removeNthFromEnd(t2, 1);
  printList(t2);

  ListNode* t3 = createList(2);
  t3 = removeNthFromEnd(t3, 2);
  printList(t3);

  ListNode* t4 = createList(5);
  t4 = removeNthFromEnd(t4, 1);
  printList(t4);

  ListNode* t5 = createList(5);
  t5 = removeNthFromEnd(t5, 5);
  printList(t5);

  ListNode* t6 = createList(5);
  t6 = removeNthFromEnd(t6, 3);
  printList(t6);

  return 0;
}
