/*
```
//my approch is

 -> minValue = is me Maxrakh do;
 left =0,right=lastindex;

 while(left<=right)
{

  //update minValue:  campare with current mid value of array

  minVal=minimum ( arr[mid],minValue);


//check left side is sorrted or not
if(arr[mid]>arr[left])// if sorted
  {


       // ager tu sorted hoi tu is ka matalab hai jo left index hai
       //vo sub se minum value hai aur right side pe may be is se b chota ho tu
hum kya krain gey minvalue update krain gey campare with minvaue and arr[left]
aur move kr jaye gey right side pe

// // // // // // // // // // //
  }
  else//ager left sorted nhi tu right sorted hai aur ye mid index saub se choti
value hai
  {
    //ab hum hume pta hai right side tu bari value hi miley tu left sid emove
kraiun gey right =mid-1
  }

}


return minvalue


```
--------------------------------------------------------------

```


Template
min = max

while (left <= right)
{
  if(min>arr[mid])

    store in min

  //move left or right

  if(arr[mid]>arr[left])//sorted left
    {
      min =min(arr[left], min)
      //move left to right
      left=mid+1;

    }
    else
    {
      move right to left

      left =left+1;



    }
}

return minVal;
```
------------------------------------------------------------------


*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int minVal = INT_MAX;
        while (left <= right) {
            int mid = right + left / 2;

            minVal = min(nums[mid], minVal);

            if (nums[mid] > nums[left]) {
                minVal = min(nums[left], minVal);
                // move right side
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return minVal;
    }
};