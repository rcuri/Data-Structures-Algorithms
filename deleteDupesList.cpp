/* Description of problem:
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
*/

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* deleteDuplicates(ListNode* head) {
  if (head == NULL || head->next == NULL) return head;

  for (ListNode** pp = &head; *pp; ) {
    ListNode* cur = *pp;
    if (cur->next && cur->val == cur->next->val) {
      int val = cur->val;
      while (cur && cur->val == val) {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
      }
      *pp = cur;
    }
    else
      pp = &((*pp)->next);
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

int main() {
  ListNode* t0 = NULL;
  t0 = deleteDuplicates(t0);
  printList(t0);

  ListNode* t1 = new ListNode(1);
  t1 = deleteDuplicates(t1);
  printList(t1);

  ListNode* t2 = new ListNode(1);
  t2->next = new ListNode(2);
  t2 = deleteDuplicates(t2);
  printList(t2);


  ListNode* t3 = new ListNode(1);
  t3->next = new ListNode(1);
  t3 = deleteDuplicates(t3);
  printList(t3);

  ListNode* t4 = new ListNode(1);
  t4->next = new ListNode(2);
  t4->next->next = new ListNode(2);
  t4->next->next->next = new ListNode(2);
  t4 = deleteDuplicates(t4);
  printList(t4);


  ListNode* t5 = new ListNode(1);
  t5->next = new ListNode(1);
  t5->next->next = new ListNode(2);
  t5->next->next->next = new ListNode(2);
  t5 = deleteDuplicates(t5);
  printList(t5);


  ListNode* t6 = new ListNode(1);
  t6->next = new ListNode(2);
  t6->next->next = new ListNode(3);
  t6->next->next->next = new ListNode(2);
  t6 = deleteDuplicates(t6);
  printList(t6);


  ListNode* t7 = new ListNode(1);
  t7->next = new ListNode(2);
  t7->next->next = new ListNode(3);
  t7->next->next->next = new ListNode(4);
  t7 = deleteDuplicates(t7);
  printList(t7);


  ListNode* t8 = new ListNode(1);
  t8->next = new ListNode(2);
  t8->next->next = new ListNode(2);
  t8->next->next->next = new ListNode(2);
  t8->next->next->next->next = new ListNode(4);
  t8 = deleteDuplicates(t8);
  printList(t8);

  ListNode* t9 = new ListNode(1);
  t9->next = new ListNode(2);
  t9->next->next = new ListNode(2);
  t9->next->next->next = new ListNode(2);
  t9->next->next->next->next = new ListNode(4);
  t9->next->next->next->next->next = new ListNode(1);
  t9->next->next->next->next->next->next = new ListNode(3);
  t9->next->next->next->next->next->next->next = new ListNode(3);
  t9->next->next->next->next->next->next->next->next = new ListNode(1);
  t9 = deleteDuplicates(t9);
  printList(t9);

  return 0;
}
