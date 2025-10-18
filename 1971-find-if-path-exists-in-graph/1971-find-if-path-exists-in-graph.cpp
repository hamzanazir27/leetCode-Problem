class Solution {
public:
    bool dfs(int node, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
        if (node == destination) 
            return true;  //  Found destination
        
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination, adj, visited))
                    return true;  //  Path found in recursion
            }
        }

        return false;  //  No path found from this node
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // undirected graph
        }

        // Step 2: Visited array
        vector<bool> visited(n, false);

        // Step 3: Run DFS
        return dfs(source, destination, adj, visited);
    }
};
