/* Description of problem:
Given an integer, write a function to determine if it is a power of three.
Try to do it without using a loop/recursion.
*/

#include <iostream>
#include <math.h>

using namespace std;

bool isPowerOfThree(int n) {
  double k = log10(n)/log10(3);
  k = fmod(k,1);
  if(k == 0)
      return true;
  return false;
}

int main() {
  if(!isPowerOfThree(0))
    cout << "0 is not a power of three." << endl;

  if(isPowerOfThree(1))
    cout << "1 is a power of three!" << endl;

  if(isPowerOfThree(3))
    cout << "3 is a power of three!" << endl;

  if(!isPowerOfThree(7))
    cout << "7 is not a power of three." << endl;

  if(isPowerOfThree(9))
    cout << "9 is a power of three!" << endl;

  if(!isPowerOfThree(21))
    cout << "21 is not a power of three." << endl;

  if(isPowerOfThree(27))
    cout << "27 is a power of three!" << endl;

  if(isPowerOfThree(2187))
    cout << "2187 is a power of three!" << endl;

  if(!isPowerOfThree(2188))
    cout << "2188 is not a power of three." << endl;

  return 0;
}
