/*

<<<<<<<<<<<Understanding 

rotated sorted array diya gaya hai, jisme array originally sorted tha, lekin kisi index par usko rotate kar diya gaya.
Example:
Original sorted array: [1, 2, 3, 4, 5, 6, 7]
Rotate karke: [4, 5, 6, 7, 1, 2, 3]

Aapko is rotated array mein target element ko efficient (fast) tarike se dhundhna hai



<<<<<<<<<<<<<<<<<<<<<<<<Approach to search target in rotated sorted array:

1. Initialize pointers:
   left = 0, right = n - 1 (start and end of array)

2. Loop while left <= right:
   - Calculate mid as left + (right - left) / 2 to avoid overflow

3. Check if nums[mid] == target:
   - If yes, return mid (target found)

4. Determine which half is sorted:
   - If nums[left] <= nums[mid], left half is sorted
   - Else, right half is sorted

5. Check if target lies in the sorted half:
   - If left half sorted and target in [nums[left], nums[mid]):
       right = mid - 1 (search left half)
   - Else if right half sorted and target in (nums[mid], nums[right]]:
       left = mid + 1 (search right half)
   - Otherwise, search in the other half by adjusting left or right

6. Continue loop until target is found or pointers cross

7. If target not found, return -1
*/


//effort more then 1 hour 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                // Check if target lies in left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                // Check if target lies in right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};


// JavaScript Code
/*
Approach:

1. Initialize pointers: left = 0, right = nums.length - 1
2. While left <= right:
   - Calculate mid = left + Math.floor((right - left) / 2)
3. If nums[mid] === target, return mid
4. Determine which half is sorted:
   - If nums[left] <= nums[mid], left half sorted
   - Else right half sorted
5. Check if target lies in sorted half:
   - If target in left half, right = mid - 1
   - Else left = mid + 1
6. Else if target in right half, left = mid + 1
   - Else right = mid - 1
7. Return -1 if not found
*/


//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-- JavaScript Version ---<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// function search(nums, target) {
//     let left = 0;
//     let right = nums.length - 1;

//     while (left <= right) {
//         let mid = left + Math.floor((right - left) / 2);

//         if (nums[mid] === target) {
//             return mid;
//         }

//         if (nums[left] <= nums[mid]) {
//             if (nums[left] <= target && target < nums[mid]) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         } else {
//             if (nums[mid] < target && target <= nums[right]) {
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
//     }

//     return -1;
// }

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<-- Python Version ---<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// def search(nums, target):
//     left, right = 0, len(nums) - 1

//     while left <= right:
//         mid = left + (right - left) // 2

//         if nums[mid] == target:
//             return mid

//         if nums[left] <= nums[mid]:
//             if nums[left] <= target < nums[mid]:
//                 right = mid - 1
//             else:
//                 left = mid + 1
//         else:
//             if nums[mid] < target <= nums[right]:
//                 left = mid + 1
//             else:
//                 right = mid - 1

//     return -1







// ///previous version good hai bs more readable oper likha hai 
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int left = 0;
//         int right = nums.size() - 1;
//         while (left <= right) {

//             int mid = (right + left) / 2;
//             if (nums[mid] == target)
//                 return mid;

//             // if left side is sorted and number is sorted no is between in left
//             // side
//             else if (nums[left] <= nums[mid] &&
//                      (nums[left] <= target && target < nums[mid]))

//             {

//                 right = mid - 1;

//             }

//             // if left side is sorted and target  not in left side

//             else if (nums[left] <= nums[mid] &&
//                      (target > nums[mid] || target < nums[left]))
//                 left = mid + 1;

//             // if right side is sorted and target is in a right side

//             else if (nums[mid] <= nums[right] &&
//                      (target <= nums[right] && target > nums[mid])) {
//                 left = mid + 1;

//             }

//             // if right side is sorted no is not in a right side
//             else {

//                 right = mid - 1;
//             }
//         } // while
//         return -1;
//     }
// };
