class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;

        for(int i=0;i<nums.size();i++)
        {
        //    4 frame rule 
         //1st Frame 

         //check deque is backed element current element smaller then pop it
         // over all we can say that this frame find maximum and place into back 
           while(!dq.empty() && nums[dq.back()]<=nums[i])
           {
            dq.pop_back();
           }

         //2nd frame  puss to queue

           dq.push_back(i);

         //3rd frame mentain window 
         if(!dq.empty() && dq.front() <= i-k)
           {
              dq.pop_front();
           }



         /// 4th frame;  if frame is correct then
         if(!dq.empty() && dq.back() >= k-1)
         {
            result.push_back(nums[dq.front()]);
         } 
        }


     return  result;
    }
    
};


/*

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        //edge case 
    if(nums.size()<2) return nums;
    if(nums.size()<3 && k!=nums.size())  return nums;


    vector<int> arr;  //
    int left=0;//

     
     for(int right=0;right<nums.size();right++)
     {

        
        if((right-left)+1==k)//1
           {
           arr.push_back(maxValue(nums,left,right));//5
           left++;
       }
        }//for
     return arr;
    };

private:
    int maxValue(vector<int>& arr,int left, int right )
    {
    int maxv = arr[left]; ;
    int i=left;
    while(i<=right)
    {
        maxv=max(arr[i],maxv);
        i++;
    }
    return maxv;
    }
};
*/