/* Reverse Integer */

/*

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
 

Constraints:

-231 <= x <= 231 - 1

*/

#include <iostream>
using namespace std;

int main() {
	// Declare a variable 'n' to
	// store the input integer.
	int n;
	// Prompt the user to enter an
	// integer and store it in 'n'.
	cin >> n;
	// Initialize a variable 'revNum' to
	// store the reverse of the input integer.
	int revNum = 0;
	// Start a while loop to reverse the
	// digits of the input integer.
	while(n > 0){
		// Extract the last digit of
		// 'n' and store it in 'ld'.
		int ld = n % 10;
		// Multiply the current reverse number
		// by 10 and add the last digit.
		revNum = (revNum * 10) + ld;
		// Remove the last digit from 'n'.
		n = n / 10;
	}
	// Print the reversed number.
	cout << revNum;
}