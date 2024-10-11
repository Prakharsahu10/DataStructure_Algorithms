/*
Alpha-Ramp
*/

/*

Sam is curious about Alpha-Ramp, so he decided to create Alpha-Ramp of different sizes.

An Alpha-Ramp is represented by a triangle, where alphabets are filled from the top in order.

For every value of ‘N’, help sam to return the corresponding Alpha-Ramp.

Example:
Input: ‘N’ = 3

Output: 
A
B B
C C C
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= N <= 25
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
A
B B
C C C
Sample Input 2 :
1
Sample Output 2 :
A
Sample Input 3 :
4
Sample Output 3 :
A
B B
C C C
D D D D

*/

#include <bits/stdc++.h>
using namespace std;

void pattern16(int N)
{
    
      // Outer loop for the number of rows.
      for(int i=0;i<N;i++){
          
          // Defining character for each row.
          char ch = 'A'+i;
          for(int j=0;j<=i;j++){
              
              // same char is to be printed i times in that row.
              cout<<ch<<" ";
              
          }
          // As soon as the letters for each iteration are printed, we move to the
          // next row and give a line break otherwise all letters
          // would get printed in 1 line.
          cout<<endl;
          
      }
}

int main()
{   
    // Here, we have taken the value of N as 5.
    // We can also take input from the user.
    int N = 5;
    pattern16(N);

    return 0;
}