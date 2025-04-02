/*

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Helper function for recursion
void backtrack(const string &digits, const unordered_map<char, string> &mapping, int index, string currentCombination, vector<string> &result)
{
    // Base case: if we've processed all digits
    if (index == digits.size())
    {
        result.push_back(currentCombination);
        return;
    }

    // Get the letters corresponding to the current digit
    string letters = mapping.at(digits[index]);

    // Recursively append each letter to the current combination
    for (char letter : letters)
    {
        backtrack(digits, mapping, index + 1, currentCombination + letter, result);
    }
}

// Main function to generate letter combinations
vector<string> letterCombinations(string digits)
{
    if (digits.empty())
    {
        return {}; // Return empty list if input is empty
    }

    // Mapping of digits to letters (like on a phone keypad)
    unordered_map<char, string> mapping = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    vector<string> result;
    backtrack(digits, mapping, 0, "", result);
    return result;
}

// Driver code
int main()
{
    string digits = "23";
    vector<string> combinations = letterCombinations(digits);

    // Print all combinations
    for (const string &combination : combinations)
    {
        cout << combination << " ";
    }
    return 0;
}
// Output: ad ae af bd be bf cd ce cf
// Time Complexity: O(4^n) where n is the length of the input string
// Space Complexity: O(n) for the recursion stack and the result storage
// Note: The actual space complexity can be higher due to the storage of the result vector, which can grow exponentially with the number of combinations.
// The space complexity of the recursion stack is O(n) where n is the length of the input string. This is because in the worst case, we can have a recursion depth equal to the length of the input string.
// The space complexity of the result vector is O(4^n) where n is the length of the input string. This is because each digit can map to 3 or 4 letters, and in the worst case, we can have 4^n combinations.
// The overall space complexity is O(4^n + n) which simplifies to O(4^n) in terms of big O notation.
// The time complexity is O(4^n) because we are generating all possible combinations of letters for the given digits, and in the worst case, we can have 4^n combinations.
// The time complexity of the backtrack function is O(4^n) where n is the length of the input string. This is because we are generating all possible combinations of letters for the given digits, and in the worst case, we can have 4^n combinations.
// The time complexity of the letterCombinations function is O(4^n) where n is the length of the input string. This is because we are generating all possible combinations of letters for the given digits, and in the worst case, we can have 4^n combinations.
// The time complexity of the main function is O(4^n) where n is the length of the input string. This is because we are generating all possible combinations of letters for the given digits, and in the worst case, we can have 4^n combinations.
// The time complexity of the entire program is O(4^n) where n is the length of the input string. This is because we are generating all possible combinations of letters for the given digits, and in the worst case, we can have 4^n combinations.