/*

Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.



Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.

*/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int pre = 1, suff = 1;
        int ans = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;

            pre *= nums[i];
            suff *= nums[n - i - 1];

            ans = max(ans, max(pre, suff));
        }

        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// where n is the number of elements in the array.
// The time complexity is O(n) because we are iterating through the array once.
// The space complexity is O(1) because we are not using any extra space that grows with the input size.