/*

Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.



Example 1:

Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1.
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2).
Example 2:

Input: nums = [44,22,33,11,1], threshold = 5
Output: 44


Constraints:

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 106
nums.length <= threshold <= 106

*/

class Solution
{
private:
    int sumByD(vector<int> &nums, int div)
    {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            sum = sum + ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= threshold)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};
// Time Complexity: O(nlog(max(nums)))
// Space Complexity: O(1)   
// The space complexity is O(1) because we are using a constant amount of space for variables and not using any additional data structures that grow with the input size.
// The time complexity is O(nlog(max(nums))) because we are iterating through the array of size n for each divisor in the range from 1 to max(nums), which is log(max(nums)).
// The overall complexity is O(nlog(max(nums))) because the binary search will take log(max(nums)) iterations and for each iteration, we are iterating through the array of size n.
