class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        if (length < 3)
            return {}; // If less than 3 elements, no triplet possible

        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort array

        for (int i = 0; i < length - 2; i++) {
            // skip dublications
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = length - 1;
            int target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
              

                 if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                // Skip duplicates for left pointer
                while (left < right && nums[left] == nums[left - 1])
                    left++;

                // Skip duplicates for right pointer
                while (left < right && nums[right] == nums[right + 1])
                    right--;
                 }
                 else if(sum<target)
                 {
                    left++;
                 }
                 else
                 {
                    right--;
                 }
            }
        }
        return result;
    }
};