#include <functional>
/*

Remove Duplicates in-place from Sorted Array

*/

/*

Example 1:
Input:
 arr[1,1,2,2,2,3,3]

Output:
 arr[1,2,3,_,_,_,_]

Explanation:
 Total number of unique elements are 3, i.e[1,2,3] and Therefore return 3 after assigning [1,2,3] in the beginning of the array.

Example 2:
Input:
 arr[1,1,1,2,2,3,3,3,3,4,4]

Output:
 arr[1,2,3,4,_,_,_,_,_,_,_]

*/

function removeDuplicates(arr) {    
    let i = 0; 
    for (let j = 1; j<arr.length; j++) {
        if(arr[i] !== arr[j]) {   
            i++;
            arr[i] = arr[j];
          i++;
            arr[i] = arr[j]; 
        }
    }
    return i+1; 
}

const arr = [1,1,2,2,2,3,3];
const k = removeDuplicates(arr);

console.log("The array after removing duplicate elements is: ");
for (let i = 0; i<k; i++) {
    console.log(arr[i]);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// where n is the number of elements in the array.
// The time complexity is O(n) because we are iterating through the array once.
// The space complexity is O(1) because we are not using any extra space that grows with the input size.