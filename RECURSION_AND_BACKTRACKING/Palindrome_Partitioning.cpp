/*

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }

private:
    void func(int index, string s, vector<string> &path, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); ++i)
        {

            if (isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};

// Time Complexity: O(2^n * n) where n is the length of the string s. The 2^n comes from the fact that we can have at most 2^n partitions, and for each partition, we need to check if it is a palindrome which takes O(n) time.
// Space Complexity: O(n) for the recursion stack and the path vector. The maximum depth of the recursion stack is n, and the path vector can also store at most n strings in the worst case.