class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        backtrak(0, used, temp, result, nums);
        return result;
    };

    void backtrak(int i, vector<bool>& used, vector<int>& temp,
                  vector<vector<int>>& result, vector<int>& nums) {
        if (i == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int j = 0; j< nums.size(); j++) {
            // skip condition
            if (used[j])
                continue;
            // chose
            temp.push_back(nums[j]);
            used[j] = true;

            // back track
            backtrak(i + 1, used, temp, result, nums);

            // undo
            temp.pop_back();
            used[j] = false;

            //     //back track
            //    backtrak(i+1,,temp,result,nums);
        }
    }
};