class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       //
       int len=profits.size();
       vector<pair<int,int>> projects;
       for(int i=0;i<len;i++)
       {
        projects.push_back({capital[i],profits[i]});
       }
        
    sort(projects.begin(),projects.end());

    priority_queue<int> maxHeap;

  int j=0;
  for(int i=0;i<k;i++)
  {

       while(j < len && projects[j].first <= w)
       {
        maxHeap.push(projects[j].second);
        j++;
       }

     if(maxHeap.empty()) 
     break;
     w +=maxHeap.top();

     maxHeap.pop();

     
      





  }

  return w;



    }
};