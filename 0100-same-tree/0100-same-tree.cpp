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
    
    void temp(vector<int> &ans, TreeNode* root){
        if(root==NULL){
            ans.push_back(0);
            return;
        }
        ans.push_back(root->val);
        temp(ans,root->left);
        temp(ans,root->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> ans,ans2;
        temp(ans,p);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<",";
        }
        cout<<endl;
        temp(ans2,q);
        for(int i=0;i<ans2.size();i++){
            cout<<ans2[i]<<",";
        }
        if(ans==ans2) return true;
        return false;
    }
};