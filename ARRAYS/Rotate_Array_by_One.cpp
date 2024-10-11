/* Left Rotate the Array by One */
/*

Example 1:
Input:
 N = 5, array[] = {1,2,3,4,5}
Output:
 2,3,4,5,1
Explanation:
 
Since all the elements in array will be shifted 
toward left by one so ‘2’ will now become the 
first index and and ‘1’ which was present at 
first index will be shifted at last.


Example 2:
Input:
 N = 1, array[] = {3}
Output:
 3
Explanation:
 Here only element is present and so 
the element at first index will be shifted to 
last index which is also by the way the first index.

*/

function solve(arr,n) {
    let temp = arr[0]; // storing the first element in a temporary variable
    for(let i = 0; i<n-1; i++) {
        arr[i] = arr[i+1]; // shifting the elements to the left by one
    }
    arr[n-1] = temp; // storing the first element at the last index
    for(let i = 0; i<n; i++) {
        console.log(arr[i] + " ");
    }
}

let n = 5;
let arr = [1,2,3,4,5];
solve(arr,n);