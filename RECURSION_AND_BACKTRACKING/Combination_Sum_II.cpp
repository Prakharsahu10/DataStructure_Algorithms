/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/

class Solution
{
public:
    void backtrack(int start, int target, vector<int> &candidates,
                   vector<int> &combination, vector<vector<int>> &result)
    {
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;
            combination.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates, combination,
                      result);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, combination, result);
        return result;
    }
};

// The time complexity of this solution is O(2^n), where n is the number of candidates. This is because we are exploring all possible combinations of candidates, and in the worst case, we may have to explore all 2^n combinations. The space complexity is O(n), where n is the maximum depth of the recursion stack.
// This is because the maximum depth of the recursion stack is equal to the number of candidates, and we are using a combination vector to store the current combination of candidates. The space complexity for storing the result is O(k), where k is the number of valid combinations found.