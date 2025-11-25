class Solution {
public: 
    bool isCylicDFS(int src,vector<vector<int>>& adjList,vector<bool>& visit,vector<bool>& isRecursive)
    {
         isRecursive[src]=true;
         visit[src]=true;

        for(auto naib:adjList[src])
        {
                if(!visit[naib])
                {
                   if(isCylicDFS(naib,adjList,visit,isRecursive))
                   {
                      return true;
                   }
                }
                else if(isRecursive[naib])
                {
                      return true;
                }
        }

         
        
      isRecursive[src]=false;
      return false;


    }


public: 
    void topoLog(int src,vector<vector<int>>& adjList,vector<bool>& visit,stack<int>& s)
    {
         visit[src]=true;

        for(auto naib:adjList[src])
        {
                if(!visit[naib])
                {
                   topoLog(naib,adjList,visit,s);
                }
             
        }

         
        
      
      s.push(src);


    }


public:
    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjList(n);
        vector<bool> visit(n, false);
        vector<bool> isRecursive(n, false);

        for(auto& edge:edges)
        {
            //u -> v
            // u[1] -> v[0]
            int u= edge[1];
            int v= edge[0];
            adjList[u].push_back(v);

        }

        for(int i=0;i<n;i++)
        {
            if(!visit[i])
              {
                if(isCylicDFS(i,adjList,visit,isRecursive))
                {
                    return {};
                }
              }
        } 


        stack<int> s;
        vector<bool> visit2(n, false);
         for(int i=0;i<n;i++)
        {
            if(!visit2[i])
              {
                topoLog(i,adjList,visit2,s);
         
              }
        } 

         vector<int> result;
        for(int i=0;i<n;i++)
        {
            int a =s.top();
            s.pop();
            result.push_back(a);

        } 



        return result;








       

         
        


        
    }
};