/*
Star Diamond
*/

/*

Ninja was very fond of patterns. For a given integer ‘N’, he wants to make the N-Star Diamond.

Example:
Input: ‘N’ = 3

Output:

  *
 ***
*****
*****
 ***
  *
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1  <= N <= 20
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
  *
 ***
*****
*****
 ***
  *
Sample Input 2 :
1
Sample Output 2 :
*
*

*/

void nStarDiamond(int n)
{

    int nsp = n - 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= nsp; j++)
        {

            cout << " ";
        }

        for (int k = 1; k <= 2 * i - 1; k++)
        {

            cout << "*";
        }

        cout << endl;

        nsp--;
    }

    int stars = 2 * n - 1;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i - 1; j++)
        {

            cout << " ";
        }

        for (int j = stars; j >= 1; j--)
        {

            cout << "*";
        }

        cout << endl;

        stars = stars - 2;
    }
}