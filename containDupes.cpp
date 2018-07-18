/*Description of problem:
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
  if(nums.size() == 0 || nums.size() == 1)
    return false;
  unordered_map<int, bool> m_map;

  for(int i = 0; i < nums.size(); i++) {
    if(m_map[nums[i]])
      return true;
    m_map[nums[i]] = true;
  }

  return false;
}

void printStatus(vector<int>& nums) {
  if(containsDuplicate(nums))
    cout << "Contains duplicate." << endl;
  else
    cout << "Does not contain duplicate." << endl;
}
int main() {
  vector<int> t1{};
  vector<int> t2{0};
  vector<int> t3{1, 0, 0};
  vector<int> t4{0, 1, 2, 4, 1};
  vector<int> t5{1, 2, 1, 3, 2, 1};
  vector<int> t6{1, 2, 3, 5, 4};

  printStatus(t1);
  printStatus(t2);
  printStatus(t3);
  printStatus(t4);
  printStatus(t5);
  printStatus(t6);

  return 0;
}
