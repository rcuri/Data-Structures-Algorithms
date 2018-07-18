/*Description of problem:
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct TreeNode* newNode(int val) {
  struct TreeNode* node = (struct TreeNode*)
                            malloc(sizeof(struct TreeNode));
  node->val  = val;
  node->left  = NULL;
  node->right = NULL;

  return(node);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
  if(!p && !q)
    return true;
  if(!p && q)
    return false;
  if(p && !q)
    return false;
  if(p->val == q->val)
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  else
    return false;

}

/* Will run tests here */
int main() {
  TreeNode* t1 = newNode(1);
  TreeNode* t2 = newNode(1);
  t1->left = newNode(2);
  t2->left = newNode(3);
  if(isSameTree(t1,t2) || isSameTree(t2,t1))
    cout << "Same!" << endl;
  else
    cout << "Not the same." << endl;


  TreeNode* t3 = newNode(1);
  TreeNode* t4 = NULL;
  t3->left = newNode(2);

  if(isSameTree(t3,t4) || isSameTree(t4,t3))
    cout << "Same!" << endl;
  else
    cout << "Not the same." << endl;


  TreeNode* t5 = newNode(1);
  TreeNode* t6 = newNode(1);
  t5->left = newNode(2);
  t6->left = newNode(2);
  t5->right = newNode(3);
  t6->right = newNode(3);
  if(isSameTree(t5,t6) || isSameTree(t6,t5))
    cout << "Same!" << endl;
  else
    cout << "Not the same." << endl;


  t5->left->left = newNode(7);
  if(isSameTree(t5,t6) || isSameTree(t6,t5))
    cout << "Same!" << endl;
  else
    cout << "Not the same." << endl;

  return 0;
}
