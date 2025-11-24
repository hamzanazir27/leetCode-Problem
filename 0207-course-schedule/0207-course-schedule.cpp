class Solution {

public:
    bool isCyclic(int src,vector<bool>& vist,vector<bool>& recPath,vector<vector<int>>& edges)
    {
       vist[src]=true;
       recPath[src]=true;
       
       for(auto& path:edges)
       {
        int u=path[1];
        int v=path[0];// u-> v  (u is prerequset)
        if(src==u) //src node is equal to u(pre req) so now 
        {
           if(!vist[v]) // if already visited
           {
              if(isCyclic(v,vist, recPath,edges))  
                return true;
           }
           else if(recPath[v])
              return true;
        }//etc


       }

      recPath[src]=false;
      return false;

    }


public:
    bool canFinish(int n, vector<vector<int>>& edges) {
     vector<bool> vist(n,false);
     vector<bool> recPath(n,false);

     for(int i=0; i<n;i++)
     {
         if(!vist[i])
          {if(isCyclic(i,vist, recPath,edges))
               return false;

          }

     }

     return true;
    }
};