/*
()

(()) ()()

((())) (()()) ()()() (())() ()(())

=
*/





class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        stack<tuple<string,int,int>> st;
        st.push({"",n,n});
        while(!st.empty())
        {   
            auto [str,openBleft,closeBleft]=st.top();
            st.pop();
            
            if(openBleft==0 &&  closeBleft==0)
             result.push_back(str);
           //base case 
           if(openBleft>0)
           {
            st.push({str+"(",openBleft-1,closeBleft}); //(
           }
           if(closeBleft>openBleft)  
           {
             st.push({str+")",openBleft,closeBleft-1});
           }



        }

        return result;

    }
};