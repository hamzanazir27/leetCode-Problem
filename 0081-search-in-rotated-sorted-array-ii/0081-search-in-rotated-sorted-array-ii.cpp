class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {

            // int mid = (right + left) / 2;
            int mid =left + (right-left)/2;

            

             if(nums[mid]==target)
               return true;
// Skip duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            }


            // left side is sorted
            else if (nums[left] <= nums[mid]) {
                // target in a left side
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    // target not in a left side
                    left = mid + 1;
                }

            }
            // right side sorted
            else {
                // target in a right side
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    // target not in a right side
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};