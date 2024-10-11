/* Palindrome Number */

/*

Given an integer x, return true if x is a 
palindrome
, and false otherwise.

 

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

Constraints:

-231 <= x <= 231 - 1

*/

#include <iostream>
using namespace std;

// Function to check if a
// given integer is a palindrome
bool palindrome(int n)
{
    // Initialize a variable to
    // store the reverse of the number
    int revNum = 0;
    // Create a duplicate variable to
    // store the original number
    int dup = n;
    // Iterate through each digit of
    // the number until it becomes 0
    while (n > 0) {
        // Extract the last
        // digit of the number
        int ld = n % 10;
        // Build the reverse number
        // by appending the last digit
        revNum = (revNum * 10) + ld;
        // Remove the last digit
        // from the original number
        n = n / 10;
    }
    // Check if the original number
    // is equal to its reverse
    if (dup == revNum) {
        // If equal, return true
        // indicating it's a palindrome
        return true;
    } else {
        // If not equal, return false
        // indicating it's not a palindrome
        return false;
    }
}


int main() {
    int number = 4554;

    if (palindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}