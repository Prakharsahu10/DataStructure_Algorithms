/* Subarray Sum equals K */
/*

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2

Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107

*/

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> subNum; // Hash map to store prefix sums and their counts
        subNum[0] = 1;                  // Initial condition for subarrays starting at the beginning
        int total = 0, count = 0;       // `total` tracks the prefix sum, `count` stores the result

        for (int n : nums)
        {
            total += n; // Update the running total (prefix sum)

            // Check if (total - k) exists in the map
            if (subNum.find(total - k) != subNum.end())
            {
                count += subNum[total - k]; // Add the count of subarrays with sum `k`
            }

            // Update the hash map with the current prefix sum
            subNum[total]++;
        }

        return count; // Total number of subarrays with sum `k`
    }
};
