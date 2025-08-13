/*
Understanding
-------------
We are given a rotated sorted array that may contain duplicates.
We need to search if the target value exists in the array or not.
The array is rotated, so normal binary search won't directly work.
Duplicates make it harder to detect which side is sorted.

Approach
--------
We will use a modified binary search:
1. Calculate mid.
2. If nums[mid] == target → return true.
3. If nums[left], nums[mid], nums[right] are all equal → skip duplicates by left++ and right--.
4. Else if left half is sorted → check if target is in this range.
5. Else right half is sorted → check if target is in this range.
6. Keep narrowing the search space until found or left > right.

Template Pseudocode 
-------------------
while left <= right:
    mid = (left + right) // 2
    if nums[mid] == target: return true
    
    if nums[left] == nums[mid] == nums[right]:
        left++
        right--
    else if nums[left] <= nums[mid]: # left side sorted
        if nums[left] <= target < nums[mid]:
            right = mid - 1
        else:
            left = mid + 1
    else: # right side sorted
        if nums[mid] < target <= nums[right]:
            left = mid + 1
        else:
            right = mid - 1
return false

Things Which Struggle
---------------------
- Detecting which side is sorted when duplicates exist.
- Avoiding infinite loops when all three (left, mid, right) are equal.
- Making sure indexes stay valid when skipping duplicates.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return true;

            // Skip duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            // Left side is sorted
            else if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // Right side is sorted
            else {
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};

/*
# Python Code

def search(nums, target):
    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return True

        if nums[left] == nums[mid] == nums[right]:
            left += 1
            right -= 1
        elif nums[left] <= nums[mid]:
            if nums[left] <= target < nums[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if nums[mid] < target <= nums[right]:
                left = mid + 1
            else:
                right = mid - 1
    return False
*/

/*
# JavaScript Code

function search(nums, target) {
    let left = 0, right = nums.length - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (nums[mid] === target) return true;

        if (nums[left] === nums[mid] && nums[mid] === nums[right]) {
            left++;
            right--;
        } else if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}
*/
