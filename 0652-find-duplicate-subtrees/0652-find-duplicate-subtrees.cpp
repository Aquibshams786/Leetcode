class Solution {
public:
    
    // declare an unordered map
    
    unordered_map<string, int> mp;
    
    // declare a res array
    
    vector<TreeNode*> res;
    
    // function for finding duplicate subtree
    
    string dfs(TreeNode* root)
    {
        // base case
        
        if(root == NULL)
        {
            return "";
        }
        
        // find the subtree for the curr node and store in str
        
        string str = "";
        
        str += to_string(root -> val);
        
        // provide delimeter
        
        str += "#";
        
        // call for left subtree
        
        string left = dfs(root -> left);
        
        str += left;
        
        // provide delimeter
        
        str += "#";
        
        // call for right subtree
        
        string right = dfs(root -> right);
        
        str += right;
        
        // increment the count of str
        
        mp[str]++;
        
        // if we found duplicate subtree then include the root into result
        
        if(mp[str] == 2)
        {
            res.push_back(root);
        }
        
        // return str
        
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        dfs(root);
        
        return res;
    }
};