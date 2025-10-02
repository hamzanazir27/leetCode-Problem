// recursion approch 


class Solution3 {
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
         if(n==1)
           return nums[0];
    

        int a= helper(n-1,1 ,nums);
        int b= helper(n-2,0, nums);
        return max(a,b);
        
    }

    int helper(int index , int end ,vector<int>& nums)
    {
        if(index<end) return 0;  
        if(index==end) return nums[end];
          
           
                 

        int rob=nums[index]+helper(index-2,end,nums);
        int skip=helper(index-1,end,nums);


        return max(skip , rob);
                   
    }
};


// dp approch memorization approch 1

class Solution{
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
         if(n==1)
           return nums[0];
    
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);

        int a= helper(n-1,1 ,nums,dp1);
        int b= helper(n-2,0, nums,dp2);
        return max(a,b);
        
    }

    int helper(int index , int end ,vector<int>& nums,vector<int> &dp)
    {
        if(index<end) return 0;  
        if(index==end) return nums[end];
        if(dp[index]!=-1)
        {
            return dp[index];
        } 
           
                 

        int rob=nums[index]+helper(index-2,end,nums,dp);
        int skip=helper(index-1,end,nums,dp);

          
        return dp[index]=max(skip , rob);
                   
    }
};