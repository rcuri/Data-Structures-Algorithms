/* Description of problem:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

#include <iostream>
#include <vector>

using namespace std;

void moveZeros(vector<int>& nums) {
  int place = 0;
  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] != 0) {
      nums[place] = nums[i];
      place++;
    }
  }
  for(int i = place; i < nums.size(); i++)
    nums[i] = 0;
}

void printVector(vector<int>& nums) {
  for(int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";
  cout << endl;
}


/* Will run tests here */
int main () {
  vector<int> t1{0};
  vector<int> t2{0, 1, 0};
  vector<int> t3{0, 1};
  vector<int> t4{1, 0};
  vector<int> t5{1, 0, 0};
  vector<int> t6{-1, 0, 3, 0, 1, 0, 0, 1};
  vector<int> t7{-1, 0, 3, 0, 1, 0, 0};

  moveZeros(t1);
  moveZeros(t2);
  moveZeros(t3);
  moveZeros(t4);
  moveZeros(t5);
  moveZeros(t6);
  moveZeros(t7);

  printVector(t1);
  printVector(t2);
  printVector(t3);
  printVector(t4);
  printVector(t5);
  printVector(t6);
  printVector(t7);

  return 0;
}
