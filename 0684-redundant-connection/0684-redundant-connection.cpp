class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Parent array - initially har node apna parent
        vector<int> parent(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        
        // Process each edge
        for(auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            
            // Find roots of both nodes
            int root1 = findRoot(parent, node1);
            int root2 = findRoot(parent, node2);
            
            // Agar same root hai, matlab cycle mil gaya!
            if(root1 == root2) {
                return edge;  // Ye edge redundant hai
            }
            
            // Otherwise, union kar do (connect them)
            parent[root1] = root2;
        }
        
        return {};  // Should never reach here
    }
    
private:
    int findRoot(vector<int>& parent, int node) {
        // Path compression ke saath root find karo
        if(parent[node] != node) {
            parent[node] = findRoot(parent, parent[node]);
        }
        return parent[node];
    }
};