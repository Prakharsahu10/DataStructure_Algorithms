/*

Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.

Note: Consider 0 based indexing

Examples:

Example 1:
Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
Output: 4
Explanation: As the target value is 13 , it appears for the first time at index number 2.

Example 2:
Input: N = 7, target=60, array[] = {3,4,13,13,13,20,40}
Output: -1
Explanation: Target value 60 is not present in the array

*/

#include <bits/stdc++.h>
int firstOccurence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return first;
}

int lastOccurence(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurence(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurence(arr, n, k);
    return {first, last};
}

int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int n = 7, k = 13;
    pair<int, int> p = firstAndLastPosition(arr, n, k);
    cout << "The first occurrence is at index: " << p.first << "\n";
    cout << "The last occurrence is at index: " << p.second << "\n";
    return 0;
}