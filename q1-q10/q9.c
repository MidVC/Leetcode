#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x){

  int digits[10];
  int len = 0;

  // If x is positive, then check if x is palindrome
  if (x >= 0) {

    // Obtain all the digits of the number x
    int num = x;
    while (num != 0) {
      int dig = num % 10;
      digits[len] = dig;
      len++;
      num /= 10;
    }

    // Check if it is palindrome
    int stop = len / 2;
    for (int i = 0; i < stop; i++) {
      int former = digits[i];
      int later = digits[len - i - 1];
      if (former != later) {
        return false;
      }
    }

    return true;
  }
  // If x is negative, then it is not palindrome
  else {
    return false;
  }
}

int main() {
    printf("%d", isPalindrome(121));
}