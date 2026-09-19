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
    bool isSame(TreeNode* A,TreeNode* B){
        if(!A && !B) return true;
        if(!A || !B) return false;

        bool l = isSame(A->left,B->left);
        bool r = isSame(A->right,B->right);
        bool c = (A->val == B->val);
        return l&r&c;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        if(root->val == subRoot->val){
            if(isSame(root,subRoot)) return true;
        } 
        bool l = isSubtree(root->left,subRoot);
        bool r = isSubtree(root->right,subRoot);
        return l|r;
    }
};
