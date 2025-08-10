


class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX ;
        int low = 0 ;
        int high =  nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2 ;

            if(nums[mid] < mini)
                mini = nums[mid] ;
            
            if(nums[low] <= nums[mid]){
                mini = min(nums[low], mini) ;
                low = mid + 1;
            }
            else
                high = mid - 1 ;
        }
        return mini; 
    }
};