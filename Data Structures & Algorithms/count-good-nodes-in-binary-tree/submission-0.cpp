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
    int solve(TreeNode* root,int maxi){
        if(!root) return 0;

        int cnt = 0;
        if(maxi <= root->val){
            cnt++;
        }
        maxi = max(maxi,root->val);
        int l = solve(root->left,maxi);
        int r = solve(root->right,maxi);
        return cnt+l+r;
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        return solve(root,-101);
    }
};
