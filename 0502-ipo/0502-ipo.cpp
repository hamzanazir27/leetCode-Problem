/*
Understanding of the Problem:
-----------------------------
- We have some initial capital 'w'.
- There are 'n' projects, each requires a minimum capital to start (capital[i])
  and gives a profit (profits[i]) when completed.
- After finishing a project, profit is added to our total capital.
- We can do at most 'k' projects.
- Goal: Maximize our final capital after completing at most k projects.

Key Observations:
-----------------
1. We can only start projects whose required capital <= our current capital 'w'.
2. Among all affordable projects, we should always pick the one with the highest profit
   (greedy choice) to maximize growth of our capital.
3. After finishing one project, our capital increases, so more projects may become affordable.
4. Repeat this process up to k times.

Approach (Greedy + Heap):
--------------------------
1. Store all projects as pairs {capital[i], profit[i]}.
2. Sort projects by required capital in ascending order.
   - Why? So that as our capital increases, we can easily know which projects
     become affordable by just moving forward in the list.
3. Use a max-heap (priority_queue in C++) to always select the project
   with the highest profit among affordable ones.
4. Iterate up to k times:
   - Push all projects into the heap whose capital requirement <= current capital.
   - If heap is empty, break (no project can be started).
   - Otherwise, pop the max profit project from heap and add its profit to capital.
5. Return the final capital after at most k projects.

Time Complexity:
----------------
- Sorting projects: O(n log n)
- Each project pushed/popped at most once from heap: O(n log n)
- Total: O(n log n + k log n), efficient enough.

Space Complexity
----------------
- projects vector stores all pairs: O(n)
- max-heap stores at most n profits: O(n)
- Other variables: O(1)
- Total = O(n)

*/

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int len = profits.size();
        vector<pair<int,int>> projects;
        
        // Step 1: Build pairs {capital_required, profit}
        for (int i = 0; i < len; i++) {
            projects.push_back({capital[i], profits[i]});
        }
        
        // Step 2: Sort projects by capital (ascending)
        sort(projects.begin(), projects.end());
        
        // Step 3: Max-heap to store profits of affordable projects
        priority_queue<int> maxHeap;
        int j = 0; // pointer for projects
        
        // Step 4: Do at most k projects
        for (int i = 0; i < k; i++) {
            // Add all newly affordable projects to heap
            while (j < len && projects[j].first <= w) {
                maxHeap.push(projects[j].second);
                j++;
            }
            
            // If no affordable projects, stop
            if (maxHeap.empty()) break;
            
            // Pick the project with max profit
            w += maxHeap.top();
            maxHeap.pop();
        }
        
        // Step 5: Return final capital
        return w;
    }
};


