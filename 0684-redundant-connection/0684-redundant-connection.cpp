class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     int N=edges.size();

    vector<int> parent(N+1);
    for(int i=0;i<=N;i++)
    {
        parent[i]=i;
    }
    
    for(auto& edge:edges)
    {
        int node1=edge[0];
        int node2=edge[1];
         
        int root1=findRoot(parent,node1);
        int root2=findRoot(parent,node2);

        if(root1 == root2)
        {
            return edge;
        }
        parent[root1]=root2;
        
    }//for

     return {};
    }
    //findRedundantConnection


    int findRoot(vector<int>& parent,int node)
    {
        if(parent[node]!=node)
        {
            parent[node]=findRoot( parent, parent[node]);
        }
        return parent[node];
    }
};