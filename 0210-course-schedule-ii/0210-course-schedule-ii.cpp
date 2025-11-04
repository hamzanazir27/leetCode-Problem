class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> count;
        queue<int> q;
        for (auto& ele : prerequisites) {
            int a = ele[0];
            int b = ele[1];

            graph[b].push_back(a);
            count[a]++;
            if (count.find(b) == count.end()) {
                count[b] = 0;
            }
        }

        for (int i = 0; i < numCourses; i++) {
            if (count[i] == 0)
                q.push(i);
       
     }
        
      

        vector<int> result;
        while (!q.empty()) {
            
            int a = q.front();
            q.pop();
            result.push_back(a);

            for (auto& neibCourse : graph[a])
                if (count.find(neibCourse) != count.end()) {
                    count[neibCourse]--;
                    if (count[neibCourse] == 0) {
                        q.push(neibCourse);
                    }
                }
        }

        if (result.size() != numCourses)
            return {};

        return result;

    }
};