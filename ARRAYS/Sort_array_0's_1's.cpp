/* Sort an array of 0s,1s and 2s */
/*

Problem Statement: Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

Examples
Input:
 nums = [2,0,2,1,1,0]
Output
: [0,0,1,1,2,2]

Input:
 nums = [2,0,1]
Output:
 [0,1,2]

Input:
 nums = [0]
Output:
 [0]

*/

#include <bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr, int n)
{

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }
    // Replace the places in the original array:
    for (int i = 0; i < cnt0; i++)
        arr[i] = 0; // Replacing 0's
    for (int i = cnt0; i < (cnt0 + cnt1); i++)
        arr[i] = 1; // Replacing 1's
    for (int i = (cnt0 + cnt1); i < n; i++)
        arr[i] = 2; // Replacing 2's
}

int main()
{
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 1, 0};
    sortArray(arr, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}