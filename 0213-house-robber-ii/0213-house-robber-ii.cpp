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


// dp approch memorization approch 1 topdown

class Solution2{
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


// dp approch memorization approch 1 bottom up

class Solution{
public:
    int rob(vector<int>& nums) {
         int n=nums.size();
         if(n==1)
           return nums[0];

         if(n==2)
           return max(nums[0],nums[1]);
    

        int a= helper(0,n-2,nums);
        int b= helper(1,n-1, nums);
        return max(a,b);
        
    }

    int helper(int start , int end ,vector<int>& nums)
    {
        vector<int> dp(nums.size()+1,-1);

         
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
           
        for(int i=start+2;i<=end;i++)
        {
        int rob=nums[i]+dp[i-2];
        int skip=dp[i-1];
         dp[i]=max(skip , rob);
        }         

        

          
        return dp[end];
                   
    }
};