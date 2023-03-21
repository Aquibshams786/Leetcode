/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return NULL;
        int ans=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
                ans++;
                int n=q.size();
                for(int i=0;i<n;i++){
                    Node* temp=q.front();
                    q.pop();
                    for(auto child: temp->children)
                        if(child) q.push(child);
                }
        }
        return ans;
    }
};