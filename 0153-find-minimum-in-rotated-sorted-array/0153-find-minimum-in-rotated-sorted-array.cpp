/*Understanding
We are given a rotated sorted array with unique elements, and we need to find the minimum element.

Key observations:

A rotated sorted array is originally sorted in ascending order but then rotated at some pivot.

At least one side (left or right) of the mid element will always be sorted.

The smallest element is either:

The first element of a sorted segment

Or lies in the unsorted segment

Our goal:

Use Binary Search to find the minimum in O(log n) time without scanning the whole array.





Approach
Initialize

left = 0

right = last index

minVal = +∞ (so that any element we find will be smaller)

Iterate while left <= right:

Compute mid = (left + right) / 2

Update minVal = min(minVal, nums[mid])

Check if the left side is sorted:

If nums[mid] >= nums[left]

This means the left portion is sorted, so the smallest element in this portion is nums[left].

Update minVal = min(minVal, nums[left]).

Move to the right side → left = mid + 1.

Else (left side not sorted, so right side must be sorted):

The smallest value must be on the left side.

Move to the left side → right = mid - 1.

Return minVal after the loop ends.




Template

minVal = +∞
left = 0
right = n - 1

while left <= right:
    mid = (left + right) / 2

    minVal = min(minVal, nums[mid])

    if nums[mid] >= nums[left]:  // Left side is sorted
        minVal = min(minVal, nums[left])
        left = mid + 1           // Search right half
    else:                        // Right side is sorted
        right = mid - 1          // Search left half

return minVal
```


previous version #########################################################################################

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




//------------------------------------Python --------------------------
//------------------------------------------------------------------
// class Solution:
//     def findMin(self, nums):
//         left = 0
//         right = len(nums) - 1
//         minVal = float('inf')

//         while left <= right:
//             mid = (left + right) // 2

//             minVal = min(nums[mid], minVal)

//             if nums[mid] > nums[left]:  # left side sorted
//                 minVal = min(nums[left], minVal)
//                 left = mid + 1
//             else:
//                 right = mid - 1

//         return minVal





//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>JavaScript Version<<<<<<<<<<<<<<<<<<<<<<<<<<<

// var findMin = function(nums) {
//     let left = 0;
//     let right = nums.length - 1;
//     let minVal = Infinity;

//     while (left <= right) {
//         let mid = Math.floor((left + right) / 2);

//         minVal = Math.min(nums[mid], minVal);

//         if (nums[mid] > nums[left]) { // left side sorted
//             minVal = Math.min(nums[left], minVal);
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }

//     return minVal;
// };
