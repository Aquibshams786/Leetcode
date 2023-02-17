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
    vector<int> ans;
    void inorder(TreeNode* T){
        if(T==NULL){
            return ;
        }
        inorder(T->left);
        ans.push_back(T->val);
        inorder(T->right);
       
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        sort(ans.begin(),ans.end());
        int result=INT_MAX;  
        for(int i=0;i+1<ans.size();++i){  
             if(ans[i+1]-ans[i]<result){
                result=ans[i+1]-ans[i];
             }
        }
        return result;;
    }
};