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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        TreeNode* leftM = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightM = lowestCommonAncestor(root->right,p,q);

        if(root == p || root == q){
            return root;
        }
        if(leftM && rightM) return root;
        if(leftM) return leftM;
        if(rightM) return rightM;
        return nullptr;
    }
};
