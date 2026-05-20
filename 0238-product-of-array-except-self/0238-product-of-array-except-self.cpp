class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
       vector<int> arr(len,1);
       //pass 1 store multiplication from left to till this element except this elment 
       for(int i = 1;i<len;i++)
       {
        arr[i]=arr[i-1]*nums[i-1];
       }

       //pass 2 start from end store all elemeent except this 

       int temp=1;
       for(int i=len-1;i>=0;i--)
       {
        arr[i]=arr[i]*temp;
        temp=nums[i]*temp;
       }
       return arr;
    }
};