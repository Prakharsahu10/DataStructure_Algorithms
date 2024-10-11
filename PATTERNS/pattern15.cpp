/*
Reverse Letter Triangle
*/

/*

Aryan and his friends are very fond of patterns. For a given integer ‘N’, they want to make the Reverse Letter Triangle.

You must print a matrix corresponding to the given Reverse Letter Triangle.

Example:
Input: ‘N’ = 3

Output: 

A B C
A B
A
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= N <= 20
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
A B C
A B
A
Sample Input 2 :
4
Sample Output 2 :
A B C D
A B C
A B
A
Sample Input 3 :
7
Sample Output 3 :
A B C D E F G 
A B C D E F 
A B C D E 
A B C D 
A B C 
A B 
A 

*/

#include <bits/stdc++.h>
using namespace std;

void pattern15(int N)
{
    
      // Outer loop for the number of rows.
      for(int i=0;i<N;i++){
          
          // Inner loop will loop for i times and
          // print alphabets from A to A + (N-i-1).
          for(char ch = 'A'; ch<='A'+(N-i-1);ch++){
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
    pattern15(N);

    return 0;
}