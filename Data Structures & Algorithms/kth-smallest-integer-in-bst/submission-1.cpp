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
    int k;
    int solve(TreeNode* root){
        if(!root) return -1;
        int l = solve(root->left);
        if(l != -1) return l;
        k--;
        if(k == 0) return root->val;
        int r = solve(root->right);
        if(r != -1) return r;
        
        
        return -1;
    }
    int kthSmallest(TreeNode* root, int k) {
      this->k = k;
      return solve(root);
    }
};
