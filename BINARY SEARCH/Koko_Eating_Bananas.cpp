/*

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.



Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], h = 6
Output: 23


Constraints:

1 <= piles.length <= 104
piles.length <= h <= 109
1 <= piles[i] <= 109

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int findMax(vector<int> &piles)
    {
        int maxi = INT_MIN;
        for (int pile : piles)
        {
            maxi = max(maxi, pile);
        }
        return maxi;
    }

    long long calculateTotalHours(vector<int> &piles, int hourly)
    {
        long long totalH = 0;
        for (int pile : piles)
        {
            totalH += (pile + hourly - 1) / hourly;
        }
        return totalH;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int low = 1, high = findMax(piles);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h)
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
// Time complexity: O(n log m)
// Space complexity: O(1)
// where n is the number of piles and m is the maximum number of bananas in a pile
// The time complexity is O(n log m) because we are iterating through the piles array n times and performing a binary search on the maximum number of bananas in a pile, which is log m.
// The space complexity is O(1) because we are using a constant amount of space to store the variables used in the calculations.