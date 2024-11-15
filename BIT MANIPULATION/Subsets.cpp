/* Subsets */
/*

Given an integer array nums of unique elements, return all possible
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int n = nums.size();
        int totalsubsets = 1 << n;
        vector<vector<int>> ans;
        for (int subsetMask = 0; subsetMask < totalsubsets; ++subsetMask)
        {
            vector<int> subset;
            for (int i = 0; i < n; ++i)
            {
                if (subsetMask & (1 << i))
                { // Check if the i-th bit is set
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset); // Add this subset to the result
        }

        return ans;
    }
};