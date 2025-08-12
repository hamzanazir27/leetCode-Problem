
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         // Ensure nums1 is smaller
//         if (nums1.size() > nums2.size())
//             return findMedianSortedArrays(nums2, nums1);

//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         int low = 0, high = n1;
//         int totalLeft = (n1 + n2 + 1) / 2;

//         while (low <= high) {
//             int partitionNums1 = (low + high) / 2;
//             int partitionNums2 = totalLeft - partitionNums1;

//             int maxLeftNums1 = (partitionNums1 == 0) ? INT_MIN : nums1[partitionNums1 - 1];
//             int minRightNums1 = (partitionNums1 == n1) ? INT_MAX : nums1[partitionNums1];

//             int maxLeftNums2 = (partitionNums2 == 0) ? INT_MIN : nums2[partitionNums2 - 1];
//             int minRightNums2 = (partitionNums2 == n2) ? INT_MAX : nums2[partitionNums2];

//             if (maxLeftNums1 <= minRightNums2 && maxLeftNums2 <= minRightNums1) {
//                 if ((n1 + n2) % 2 == 1) {
//                     return max(maxLeftNums1, maxLeftNums2);
//                 } else {
//                     return (max(maxLeftNums1, maxLeftNums2) + min(minRightNums1, minRightNums2)) / 2.0;
//                 }
//             } else if (maxLeftNums1 > minRightNums2) {
//                 high = partitionNums1 - 1;
//             } else {
//                 low = partitionNums1 + 1;
//             }
//         }
//         return 0.0; // Should never reach here
//     }
// };











/*  MY APPROCH 
Understanding:
--------------
We are given two sorted arrays, for example:
nums1 = [1,4,5]
nums2 = [1,2,3,6]

The task is to merge these two arrays into one sorted array and then find the median of this merged array.

What is median?
- If the merged array length is odd, median is the middle element.
- If the merged array length is even, median is the average of the two middle elements.

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Merged array = [1,2,3]
Median = 2

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Merged array = [1,2,3,4]
Median = (2 + 3) / 2 = 2.5

Approach:
---------
1. To merge, we use two pointers: num1 for nums1 and num2 for nums2.
2. **Detailed explanation of the while loop:**  
   - The loop continues until all elements from both arrays are processed (i.e., num1 < nums1.size() or num2 < nums2.size()).  
   - In each iteration, we first check if both pointers are within their respective array bounds.  
   - If both elements exist, we compare nums1[num1] and nums2[num2]:  
     - If nums1[num1] is smaller, we append it to the merged array 'arr' and increment num1.  
     - Otherwise, we append nums2[num2] to 'arr' and increment num2.  
   - If only elements of nums1 remain (nums2 is exhausted), we append all remaining nums1 elements.  
   - If only elements of nums2 remain (nums1 is exhausted), we append all remaining nums2 elements.  
   - This ensures the merged array stays sorted and all elements are included.
3. After merging, we calculate the median:  
   - If the merged array size is odd, the median is the middle element.  
   - If even, the median is the average of the two middle elements.

Challenges faced:
-----------------
- Proper boundary checking to avoid out-of-range errors during merge.
- Ensuring floating point division when calculating median to avoid integer division.
- Correctly identifying middle elements for median calculation, especially for even length arrays.
- Keeping the code clean and easy to understand.

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int num1 = 0;
        int num2 = 0;
        while (num1 < nums1.size() || num2 < nums2.size()) {
            if (num1 < nums1.size() && num2 < nums2.size() &&
                nums1[num1] > nums2[num2]) {

                arr.push_back(nums2[num2]);
                num2++;
            } else if (num1 < nums1.size() && num2 < nums2.size() &&
                       nums1[num1] < nums2[num2]) {
                arr.push_back(nums1[num1]);
                num1++;
            } else if (num1 < nums1.size()) {

                arr.push_back(nums1[num1]);
                num1++;
            }

            else

            {

                arr.push_back(nums2[num2]);
                num2++;
            }
        }

        int right = arr.size() - 1;
        int mid = right / 2;
          double median=0.0;
         if(arr.size()%2!=0)
         median = arr[mid];
         else
        median = ((arr[mid] + arr[mid + 1] )/ 2.0);
        return median;
    }
};


