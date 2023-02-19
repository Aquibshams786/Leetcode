/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int count=1;
        while(!q.empty()){
            TreeNode* node =q.front();
            q.pop();
            if(node!=NULL){
                temp.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            else if(!q.empty()){
                q.push(NULL);
                if(count%2==0){
                    reverse(temp.begin(),temp.end());
                    ans.push_back(temp);
                }
                else{
                    ans.push_back(temp);
                }
                temp.clear();
                count++;
            }
            
            
        }
        if(count%2==0){
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        else{
            ans.push_back(temp);
        }
        return ans;
    }
};