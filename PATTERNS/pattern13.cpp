/*
Increasing Number Triangle
*/

/*

Aryan and his friends are very fond of patterns. For a given integer ‘N’, they want to make the Increasing Number Triangle.

Example:
Input: ‘N’ = 3

Output: 

1
2 3
4 5 6
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= T <= 10
1  <= N <= 20
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
1
2 3
4 5 6
Sample Input 2 :
4
Sample Output 2 :
1
2 3
4 5 6 
7 8 9 10
Sample Input 3 :
7
Sample Output 3 :
1
2 3
4 5 6 
7 8 9 10
11 12 13 14 15 
16 17 18 19 20 21 
22 23 24 25 26 27 28

*/

#include <bits/stdc++.h>
using namespace std;

void pattern13(int N)
{
      // starting number
      int num =1;
      
      // Outer loop for the number of rows.
      for(int i=1;i<=N;i++){
          
          // Inner loop will loop for i times and
          // print numbers increasing by 1 each time.
          for(int j=1;j<=i;j++){
              cout<<num<<" ";
              num =num+1;
          }
          // As soon as the numbers for each iteration are printed, we move to the
          // next row and give a line break otherwise all numbers
          // would get printed in 1 line.
          cout<<endl;
          
      }
}

int main()
{   
    // Here, we have taken the value of N as 5.
    // We can also take input from the user.
    int N = 5;
    pattern13(N);

    return 0;
}