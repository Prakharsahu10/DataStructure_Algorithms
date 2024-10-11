/*

Example 1:

Input: Character
Output: 1
Explaination: For java it would be 2 bytes.

Example 2:
Input: Integer
Output: 4


Your Task:

Complete the function dataTypeSize() which takes a string as input and returns the size of the data type represented by the given string in byte unit.
Return -1 if the input data type is invalid.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dataTypeSize(string str)
    {
        if (str == "Character")
            return 1;
        else if (str == "Integer" || str == "Float")
            return 4;
        else if (str == "Long" || str == "Double")
            return 8;
        else
            return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.dataTypeSize(str);
        cout << "\n";
    }
    return 0;
}