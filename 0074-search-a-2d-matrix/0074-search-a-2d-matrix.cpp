
// ```
// //my approch

// int Bigleft=0;
// int BogRight=size-1;


// while(BigLeft <= BigRight)
// {
  
//  calculate mid
//  if(arr[mid][0]<target>arr[mid][size-1])   // if no is between in subarray
//  {
   
//   //binary search  
  
  
//   return false;// if no not exist in subarray
   
   
//  }
//  else if (arr[mid][0]>target && arr[mid][lastIndex]>target)
//  {
//    // move right  => mid -1
//  }
//  else()
//  {
//    //move left to mid +1 
//  }
 
// }



// return false; //if no is between subarray but actaul not
// ```




class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int BigLeft=0;
        int BigRight=matrix.size()-1;

        while(BigLeft <= BigRight)
        {
            //calculate Mid 
            int mid=(BigLeft+BigRight)/2;
            int lastIndex= matrix[mid].size()-1;
   


            if(matrix[mid][0]<= target && matrix[mid][lastIndex] >=target)
            {
              int left =0;
              int right = lastIndex;
              while(left <= right )
              {
               int innerMid= (left+right)/2;
                 cout<<matrix[mid][innerMid];

               if(matrix[mid][innerMid]==target)
                {
                    

                    
                    return true;

              
              
                }
              
               else if(matrix[mid][innerMid]>target && matrix[mid][innerMid]>target)
               {
                right = innerMid-1;
               }
               else
               {
                left=innerMid+1;
               }
              }//inner while 


              return false;

            }// if target in  mid sub array


            else if(matrix[mid][0]>target)
            {
               BigRight=mid-1;
            }
            else
            {
                BigLeft=mid+1;
            }



        }//Big Array while -> 


        return false;
    }
};

