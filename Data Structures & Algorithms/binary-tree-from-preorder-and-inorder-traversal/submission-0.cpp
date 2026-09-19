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
    unordered_map<int,int> mp;
    
    TreeNode* solve(vector<int> &preorder,int st,int end,int &idx){
        if(st > end) return nullptr;
        if(idx == preorder.size()) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        int pos = mp[root->val];

        root->left = solve(preorder,st,pos-1,idx);
        root->right = solve(preorder,pos+1,end,idx);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) { 
        for(int i = 0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx = 0;
        int end = preorder.size() - 1;
        return solve(preorder,0,end,idx);
    }
};
