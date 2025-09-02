class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    priority_queue<int> maxHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
     if(maxHeap.empty() || num<=maxHeap.top())
     {
        maxHeap.push(num);
     }
     else
     {
        minHeap.push(num);
     }

     //balance
     //      2             4+1
     if(maxHeap.size() > minHeap.size() +1)
     {
         minHeap.push(maxHeap.top());
         maxHeap.pop();
     }

         //      2             
     else if(minHeap.size() > maxHeap.size())
     {
         maxHeap.push(minHeap.top());
         minHeap.pop();
     }

    }

    double findMedian() {

     if(maxHeap.size()==minHeap.size())
     {
        return (minHeap.top()+maxHeap.top())/2.0;
     }
     else
     {
        return maxHeap.top();
     }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */