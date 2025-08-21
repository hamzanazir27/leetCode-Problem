class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    stack<int> stk;
    int maxArea=0;
    for(int i=0; i<heights.size();i++)
    {

        if(!stk.empty() && heights[i] < heights[stk.top()])
        {
         int topindex=stk.top();
          while(!stk.empty() && heights[i] < heights[stk.top()])
           {
               int currentIndex=stk.top();
               stk.pop();
            //      int width=0;
            //    if ((topindex-currentIndex)==0)
            //     width=1;
            //    else
            //    width=(topindex-currentIndex)+1;
               


                int width;
                if (stk.empty()) {
                    width = i; // agar stack empty hai, toh width = i
                } else {
                    width = i - stk.top() - 1; 
                }

             



               int height=heights[currentIndex];
               int area = width * height;

               maxArea=max(area,maxArea);


               





           }//while

        }//if


       stk.push(i);
    }//for
       return maxArea;
    }//func


    
};