class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {

            int mid = (right + left) / 2;
            if (nums[mid] == target)
                return mid;

            // if left side is sorted and number is sorted no is between in left
            // side
            else if (nums[left] <= nums[mid] &&
                     (nums[left] <= target && target < nums[mid]))

            {

                right = mid - 1;

            }

            // if left side is sorted and target  not in left side

            else if (nums[left] <= nums[mid] &&
                     (target > nums[mid] || target < nums[left]))
                left = mid + 1;

            // if right side is sorted and target is in a right side

            else if (nums[mid] <= nums[right] &&
                     (target <= nums[right] && target > nums[mid])) {
                left = mid + 1;

            }

            // if right side is sorted no is not in a right side
            else {

                right = mid - 1;
            }
        } // while
        return -1;
    }
};
