class MedianFinder {
    // minHeap: store larger half of numbers (always min element on top)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // maxHeap: store smaller half of numbers (always max element on top)
    priority_queue<int> maxHeap;

public:
    MedianFinder() {}

    /*
    Understanding:
    --------------
    - We need to design a data structure that supports:
        1) Adding numbers from a stream (addNum).
        2) Finding the current median efficiently (findMedian).
    
    Approach:
    ---------
    - Use two heaps:
        * maxHeap: keeps track of smaller half (left side).
        * minHeap: keeps track of larger half (right side).
    
    - Balancing condition:
        * maxHeap can have at most 1 element more than minHeap.
        * This ensures median can always be calculated from tops of heaps.

    Steps for addNum:
    -----------------
    1) If number <= maxHeap.top(), push in maxHeap (left side).
       Else, push in minHeap (right side).
    2) Balance heaps:
       - If maxHeap has more than 1 extra element -> move one to minHeap.
       - If minHeap has more elements -> move one to maxHeap.

    Steps for findMedian:
    ---------------------
    1) If both heaps have equal size -> median is average of both tops.
    2) Else, median is the top of maxHeap (because it has 1 extra element).
    */

    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num); // goes to left half
        } else {
            minHeap.push(num); // goes to right half
        }

        // Balance condition: difference in sizes should not exceed 1
        if(maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if(minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if(maxHeap.size() == minHeap.size()) {
            // even total numbers -> average of two middle values
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } else {
            // odd total numbers -> middle is top of maxHeap
            return maxHeap.top();
        }
    }
};

/*
Complexity Analysis:
--------------------
- addNum():
  * Heap insertion -> O(log n)
  * Possible rebalancing (1 pop + 1 push) -> O(log n)
  * Overall: O(log n)

- findMedian():
  * Just accessing top of heaps -> O(1)

- Space Complexity:
  * Both heaps store all elements -> O(n)

Use Case:
---------
- Useful when numbers are coming in a stream and we need
  real-time median calculation (e.g. stock prices, sensor data).
*/
