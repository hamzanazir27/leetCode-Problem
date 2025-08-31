// push all stones into maxHeap

// while heap.size > 1:
//     x = heap.pop()
//     y = heap.pop()
//     if x != y:
//         push (x-y) into heap

// if heap empty → return 0
// else return heap.top()


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> maxHeap;
        for(int stone:stones)
        {
            maxHeap.push(stone);
        }

        while(maxHeap.size()>1)
        {
            int y=maxHeap.top();
            maxHeap.pop();
            int x=maxHeap.top();
            maxHeap.pop();
            if(x!=y)
            {
                maxHeap.push(y-x);

            }
        }//while
          
         return  maxHeap.empty() ? 0 : maxHeap.top();
    }
};

