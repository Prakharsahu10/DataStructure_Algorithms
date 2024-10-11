/* Print 1 to N using Recursion */

#include <bits/stdc++.h>
using namespace std;

void func(int i, int n)
{

    // Base Condition
    if (i > n)
        return;
    cout << i << endl;

    // Function call to print i till i increments.
    func(i + 1, n);
}

int main()
{
    int n = 4;
    func(1, n);
    return 0;
}