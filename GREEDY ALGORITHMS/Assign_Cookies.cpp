/* Assign Cookies */
/*

Problem Statement: Given two arrays representing children’s green factor and cookie sizes, the goal is to maximise the number of content children.

Each child i has a greed factor of g[i], which is the minimum size of a cookie that will make the child content. Each cookie j has a size of s[j]. If s[j] >= g[j], we can assign cookie j to child i, making the child content. Each child can only receive one cookie.

Examples
Example 1:
Input:g = [1, 2, 3], s = [1, 1]

Output: 1
Explanation:  We have 3 children and 2 cookies. The greed factors of the 3 children are 1, 2, 3. The sizes of the 2 cookies are both 1. We can only make the child with greed factor 1 content. Hence, the output is 1.

*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Function to find the maximum
// number of content children
int findContentChildren(vector<int> &greed, vector<int> &cookieSize)
{
    // Get the size of
    // the greed array
    int n = greed.size();

    // Get the size of
    // the cookieSize array
    int m = cookieSize.size();

    // Sort the greed factors in ascending
    // order to try and satisfy the
    // least greedy children first
    sort(greed.begin(), greed.end());

    // Sort the cookie sizes in ascending
    // order to use the smallest cookies first
    sort(cookieSize.begin(), cookieSize.end());

    // Initialize a pointer for the
    // cookieSize array, starting
    // from the first cookie
    int l = 0;

    // Initialize a pointer for the
    // greed array, starting from
    // the first child
    int r = 0;

    // Iterate while there are
    // cookies and children
    // left to consider
    while (l < m && r < n)
    {
        // If the current cookie can
        // satisfy the current child's greed
        if (greed[r] <= cookieSize[l])
        {
            // Move to the next child,
            // as the current child is satisfied
            r++;
        }
        // Always move to the next cookie
        // whether the current child
        // was satisfied or not
        l++;
    }

    // The value of r at the end of
    // the loop represents the number
    // of children that were satisfied
    return r;
}

int main()
{
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};

    cout << "Array Representing Greed: ";
    for (int i = 0; i < greed.size(); i++)
    {
        cout << greed[i] << " ";
    }
    cout << endl;
    cout << "Array Representing Cookie Size: ";
    for (int i = 0; i < cookieSize.size(); i++)
    {
        cout << cookieSize[i] << " ";
    }

    int ans = findContentChildren(greed, cookieSize);

    cout << endl
         << "No. of kids assigned cookies " << ans;
    cout << endl;

    return 0;
}