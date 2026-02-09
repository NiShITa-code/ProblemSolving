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
    // map which stores copy of node
    unordered_map<Node*, Node*> copies;
    
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        // copy of first node
        Node* copy = new Node(node -> val, {});
        // stor it
        copies[node] = copy;
        queue<Node*> q;
        q.push(node);
        //bfs
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (Node* n: curr -> neighbors) {
                if (copies.find(n) == copies.end()) {
                    Node* ncopy = new Node(n -> val, {});
                    copies[n] = ncopy;
                    q.push(n);
                }
                copies[curr] -> neighbors.push_back(copies[n]);
            } 
        }
        return copy;
        

    }
};