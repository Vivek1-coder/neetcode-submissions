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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root) return -1e8;
        int l = solve(root->left);
        int r = solve(root->right);
        // cout<<root->val<<" "<<l<<" "<<r<<endl;
        int maxi = max({root->val,l+root->val,r+root->val});
        
        ans = max({ans,l,r});
        ans = max(ans,maxi);
        ans = max(ans,l+r+root->val);
       
        return maxi;
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
