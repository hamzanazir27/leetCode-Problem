class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // [2,-1,2], k = 3
        queue<int> q;//2 -1

        int minLen =INT_MAX ;
        int sum = 0;//1
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];//

            q.push(i);

            if (sum==k) {
                int calLen=q.back()-q.front();
                minLen = min(calLen+1, minLen);
                sum -= nums[q.front()];
                q.pop();
            }
            if(sum > k)
            { sum -= nums[q.front()];
                q.pop();}
        } // for
        return minLen==INT_MAX? -1 :minLen;
    }
};