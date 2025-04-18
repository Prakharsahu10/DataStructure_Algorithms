/*

Problem Statement: You are given a sorted array containing N integers and a number X, you have to find the occurrences of X in the given array.

Examples
Example 1:
Input:
 N = 7,  X = 3 , array[] = {2, 2 , 3 , 3 , 3 , 3 , 4}
Output
: 4
Explanation:
 3 is occurring 4 times in 
the given array so it is our answer.

Example 2:
Input:
 N = 8,  X = 2 , array[] = {1, 1, 2, 2, 2, 2, 2, 3}
Output
: 5
Explanation:
 2 is occurring 5 times in the given array so it is our answer.

*/

#include <bits/stdc++.h>
int firstOccurence(vector<int> &arr, int n, int k) {
    int low = 0, high = n-1;
    int first = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid -1;
    }
    return first;
}

int lastOccurence(vector<int> &arr, int n, int k){
    int low = 0, high = n-1;
    int last = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == k) {
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    int first = firstOccurence(arr, n , k);
    if(first == -1)
        return { -1, -1 };
        int last = lastOccurence(arr, n , k);
        return { first, last };
}

int count(vector<int>& arr, int n, int x) {
	pair<int, int> ans = firstAndLastPosition(arr, n, x);
	if(ans.first == -1) return 0;
	return ans.second - ans.first + 1;
}
