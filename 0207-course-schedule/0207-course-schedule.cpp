#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> graph;

        // Initialize indegree for all courses
        for (int i = 0; i < numCourses; i++)
            indegree[i] = 0;

        // Build graph and indegree count
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (auto& p : indegree)
            if (p.second == 0) q.push(p.first);

        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            for (int next : graph[curr]) {
                indegree[next]--;
                if (indegree[next] == 0)
                    q.push(next);
            }
        }

        return count == numCourses;
    }
};
