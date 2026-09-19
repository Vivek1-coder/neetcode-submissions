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
        if(!node) return nullptr;
        unordered_map<Node*,int> vis;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        mp[node] = new Node(node->val);
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            Node* curr = q.front();
            Node* cp = mp[curr];
            q.pop();
            vector<Node*> nbrs;
            for(Node* nbr:curr->neighbors){
                if(!vis[nbr]){
                    q.push(nbr);
                    mp[nbr] = new Node(nbr->val);
                    nbrs.push_back(mp[nbr]);
                    vis[nbr] = true;
                }
                else{
                    nbrs.push_back(mp[nbr]);
                }
            }
            cp->neighbors = nbrs;
        }
    return mp[node];
    }
};
