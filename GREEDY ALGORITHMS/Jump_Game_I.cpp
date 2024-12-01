/* Jump Game 1 */
/*

Problem Statement: Given an array where each element represents the maximum number of steps you can jump forward from that element, return true if we can reach the last index starting from the first index. Otherwise, return false.

Examples
Example 1:
Input:nums = [2, 3, 1, 0, 4]

Output: True
Explanation:

We start at index 0, with value 2 this means we can jump to index 1 or 2.
From index 1, with value 3, we can jump to index 2, 3, or 4. However, if we jump to index 2 with value 1, we can only jump to index 3.
So we jump to index 1 then index 4 reaching the end of the array.
Hence, we return true.

Example 2:
Input:nums = [3, 2, 1, 0, 4]

Output: False
Explanation:

We start at index 0, with value 3 which means we can jump to index 1, 2, or 3.
From index 1, with value 2 we can only jump to index 2 or 3.
From index 2, with value 1 we can only jump to index 3.
From index 3, with value 0 we cannot jump any further.
Hence, from all possibilities we are unable to jump to the last index so we return false.

*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Function to determine if
// you can reach the last index
bool canJump(vector<int> &nums)
{
    // Initialize the maximum
    // index that can be reached
    int maxIndex = 0;

    // Iterate through each
    // index of the array
    for (int i = 0; i < nums.size(); i++)
    {
        // If the current index is greater
        // than the maximum reachable index
        // it means we cannot move forward
        // and should return false
        if (i > maxIndex)
        {
            return false;
        }

        // Update the maximum index
        // that can be reached by comparing
        // the current maxIndex with the sum of
        // the current index and the
        // maximum jump from that index
        maxIndex = max(maxIndex, i + nums[i]);
    }

    // If we complete the loop,
    // it means we can reach the
    // last index
    return true;
}

int main()
{
    vector<int> nums = {4, 3, 7, 1, 2};

    cout << "Array representing maximum jump from each index: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    bool ans = canJump(nums);

    if (ans)
    {
        cout << "It is possible to reach the last index." << endl;
    }
    else
    {
        cout << "It is not possible to reach the last index." << endl;
    }

    return 0;
}