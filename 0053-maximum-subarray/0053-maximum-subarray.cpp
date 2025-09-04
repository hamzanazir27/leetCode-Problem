class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int maxSum=nums[0];
        for(int no:nums)
        {
            if(sum<0)
            {
                sum=0;
            }

            sum +=no;
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};