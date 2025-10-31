/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

   

public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
        {
            return nullptr;
        }
    unordered_map<Node*,Node*> mp;
    
    return helper(node,mp);
    }

    Node* helper(Node* node, unordered_map<Node*,Node*>& mp)
    {

     if(mp.find(node)!=mp.end())
     {
        return mp[node];
     }

     Node* cloneNode=new Node(node->val);
     mp[node]=cloneNode;
     for(auto neighbor:node->neighbors)
     {
         cloneNode->neighbors.push_back(helper(neighbor,mp))     ;  
     }
    

     return cloneNode;

    }
};