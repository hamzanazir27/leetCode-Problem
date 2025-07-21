class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
         double maxV = -DBL_MAX;
        int left = 0;
        for (int right=0; right< nums.size();right++)
        {

          if(right-left+1>k)
          {
            sum-=nums[left];
            left++;
          }

        sum+=nums[right];
if (right - left + 1 == k) {
    maxV = max(maxV, sum / k);
}





        }
        return maxV;
    }
};