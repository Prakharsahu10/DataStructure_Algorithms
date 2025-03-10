/*

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.

*/

// This function checks if two frequency arrays have identical values
// It compares each position in both arrays to determine if they represent the same character frequencies
bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }
    return true;
}

// This function checks if any permutation of s1 is present in s2
// It uses a sliding window approach with character frequency counting
bool checkInclusion(string s1, string s2)
{
    // If s1 is longer than s2, no permutation of s1 can be in s2
    if (s1.length() > s2.length())
        return false;

    // Initialize frequency arrays for s1 and the current window in s2
    int freq[26] = {0};        // Stores frequency of each character in s1
    int windFreq[26] = {0};    // Stores frequency of each character in current window of s2

    // Populate initial frequencies for the first window
    for (int i = 0; i < s1.length(); i++)
    {
        freq[s1[i] - 'a']++;           // Count characters in s1
        windFreq[s2[i] - 'a']++;       // Count characters in first window of s2
    }
    
    // Check if the first window is a permutation of s1
    if (isFreqSame(freq, windFreq))
        return true;

    // Slide the window through s2
    for (int i = s1.length(); i < s2.length(); i++)
    {
        // Add the new character to the window
        windFreq[s2[i] - 'a']++;
        
        // Remove the character that's no longer in the window
        windFreq[s2[i - s1.length()] - 'a']--;

        // Check if current window is a permutation of s1
        if (isFreqSame(freq, windFreq))
            return true;
    }

    // No permutation found
    return false;
}


