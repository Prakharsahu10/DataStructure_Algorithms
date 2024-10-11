/*
Ninja and the Star Pattern 1
*/

/*

Ninja has been given a task to print the required star pattern and he asked your help for the same.

You must return an ‘N’*’N’ matrix corresponding to the given star pattern.

Example:
Input: ‘N’ = 4

Output: 

****
*  *
*  *
****
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= N <= 10^2
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
***
* *
***
Sample Input 2 :
5
Sample Output 2 :
*****
*   *
*   *
*   *
*****
Sample Input 3 :
8
Sample Output 3 :
********
*      *
*      *
*      *
*      *
*      *
*      *
********

*/

#include <bits/stdc++.h>
using namespace std;

void pattern21(int n)
{
     // outer loop for no. of rows.
     for(int i=0;i<n;i++){
         
         // inner loop for printing the stars at borders only.
         for(int j=0;j<n;j++){
             
             if(i==0 || j==0 || i==n-1 || j==n-1)
                cout<<"*";
                
             // if not border index, print space.
             else cout<<" ";
         }
         
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
     }
      
}

int main()
{   
    // Here, we have taken the value of N as 5.
    // We can also take input from the user.
    int N = 5;
    
    pattern21(N);

    return 0;
}