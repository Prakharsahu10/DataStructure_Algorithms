/*

Problem Statement: Given an array of size n, write a program to check if the given array is sorted in (ascending / Increasing / Non-decreasing) order or not. If the array is sorted then return True, Else return False.

Example 1:
Input:
 N = 5, array[] = {1,2,3,4,5}
Output: True.
Explanation:
 The given array is sorted i.e Every element in the array is smaller than or equals to its next values, So the answer is True.


Example 2:
Input:
 N = 5, array[] = {5,4,6,7,8}
Output: False.
Explanation:
 The given array is Not sorted i.e Every element in the array is not smaller than or equal to its next values, So the answer is False.

Here element 5 is not smaller than or equal to its future elements.

*/

#include <bits/stdc++.h>

using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5}, n = 5;

    printf("%s", isSorted(arr, n) ? "True" : "False");
}

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using only a constant amount of space.
// The space complexity is O(1) because we are not using any extra space that grows with the input size. We are only using a few variables to store the current index and the size of the array, which do not depend on the input size. 
// Therefore, the space complexity is constant, O(1).
// The time complexity is O(n) because we are iterating through the array once, checking each element against its predecessor. This means that the time taken to run the algorithm grows linearly with the size of the input array.