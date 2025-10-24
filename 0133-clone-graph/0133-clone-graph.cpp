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
  // Map to store old node → cloned node
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        // If node already cloned, just return it
        if (mp.find(node) != mp.end()) {
            return mp[node];
        }

        // Create a new node (clone) with same value
        Node* cloneNode = new Node(node->val);
        mp[node] = cloneNode;  // store in map

        // Traverse all neighbors
        for (auto neighbor : node->neighbors) {
            // Recursively clone each neighbor
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }

};