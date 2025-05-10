/* Linear Search */
/*

Problem Statement: Given an array, and an element num the task is to find if num is present in the given array or not. If present print the index of the element or print -1.

Examples:

Example 1:
Input: arr[]= 1 2 3 4 5, num = 3
Output: 2
Explanation: 3 is present in the 2nd index

Example 2:
Input: arr[]= 5 4 3 2 1, num = 5
Output: 0
Explanation: 5 is present in the 0th index

*/

#include<stdio.h>

int search(int arr[],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==num)
        return i;
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5};
    int num = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    int val = search(arr,n,num);
    printf("%d",val);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// where n is the number of elements in the array.
// The time complexity is O(n) because we are iterating through the array once.
// The space complexity is O(1) because we are not using any extra space that grows with the input size.