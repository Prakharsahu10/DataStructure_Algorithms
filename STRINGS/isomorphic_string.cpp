/* Isomorphic string */
/*

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.



Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true



Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.

*/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false;
        }

        unordered_map<char, char> charMappingMap;
        unordered_map<char, bool> usedReplacement; // Track which replacement characters have been used

        for (int i = 0; i < s.length(); i++)
        {
            char original = s[i];
            char replacement = t[i];

            // If the original character hasn't been mapped yet
            if (charMappingMap.find(original) == charMappingMap.end())
            {
                // Ensure no two characters map to the same replacement character
                if (usedReplacement[replacement])
                {
                    return false;
                }
                charMappingMap[original] = replacement;
                usedReplacement[replacement] = true;
            }
            // If the original character is already mapped, check if it maps to the correct replacement
            else
            {
                if (charMappingMap[original] != replacement)
                {
                    return false;
                }
            }
        }
        return true;
    }
};