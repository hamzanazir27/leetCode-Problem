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
          double mdeain=0.0;
         if(arr.size()%2!=0)
         mdeain = arr[mid];
         else
        mdeain = ((arr[mid] + arr[mid + 1] )/ 2.0);
        return mdeain;
    }
};