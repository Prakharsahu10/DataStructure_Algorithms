/*

Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)

*/

class Solution
{
public:
    bool isPossible(vector<int> &nums, int k, int goal_sum)
    {
        int sum = 0, count = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] <= goal_sum)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
                count++;

                if (count > k)
                    return false;
            }
        }
        return true;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int min = *max_element(nums.begin(), nums.end());
        int max = accumulate(nums.begin(), nums.end(), 0);
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            if (isPossible(nums, k, mid))
            {
                max = mid;
            }
            else
            {
                min = mid + 1;
            }
        }
        return min;
    }
};

// Time Complexity: O(n log(sum(nums)))
// Space Complexity: O(1)
// where n is the length of the nums array and sum(nums) is the sum of all elements in nums.
// The binary search runs in O(log(sum(nums))) and the isPossible function runs in O(n).
// The overall complexity is dominated by the binary search, leading to O(n log(sum(nums))).
// The space complexity is O(1) since we are using a constant amount of extra space.
