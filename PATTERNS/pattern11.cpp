/*
Binary Number Triangle
*/

/*

Aryan and his friends are very fond of the pattern. For a given integer ‘N’, they want to make the N-Binary Number Triangle.

You are required to print the pattern as shown in the examples below.

Example:
Input: ‘N’ = 3

Output:

1
0 1
1 0 1
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= N <= 20
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
1
0 1
1 0 1
Sample Input 2 :
4
Sample Output 2 :
1
0 1
1 0 1
0 1 0 1
Sample Input 3 :
6
Sample Output 3 :
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
0 1 0 1 0 1

*/

#include <bits/stdc++.h>
using namespace std;

void pattern11(int N)
{
    // First row starts by printing a single 1.
    int start = 1;

    // Outer loop for the no. of rows
    for (int i = 0; i < N; i++)
    {

        // if the row index is even then 1 is printed first
        // in that row.
        if (i % 2 == 0)
            start = 1;

        // if odd, then the first 0 will be printed in that row.
        else
            start = 0;

        // We alternatively print 1's and 0's in each row by using
        // the inner for loop.
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }

        // As soon as the numbers for each iteration are printed, we move to the
        // next row and give a line break otherwise all numbers
        // would get printed in 1 line.
        cout << endl;
    }
}

int main()
{
    // Here, we have taken the value of N as 5.
    // We can also take input from the user.
    int N = 5;
    pattern11(N);

    return 0;
}