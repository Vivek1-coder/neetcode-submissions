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

class Codec {
public:

    void preOrder(TreeNode* root,string &ans){
        if(!root){
            ans += " o";
            return;
        }
        ans += " ";
        ans += to_string(root->val);
        preOrder(root->left,ans);
        preOrder(root->right,ans);
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        preOrder(root,ans);
        return ans;
    }

    TreeNode* solve(string data,int &idx){
        if(idx == data.size()) return nullptr;
        while(data[idx] == ' ') idx++;
        string temp = "";
        while(idx < data.size() && data[idx] != ' '){
            temp += data[idx++];
        }
        if(temp == "o") return nullptr;
        int num = stoi(temp);
        TreeNode* ans = new TreeNode(num);
        ans->left = solve(data,idx);
        ans->right = solve(data,idx);
        return ans;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == " o") return nullptr;
        int idx = 0;
        return solve(data,idx);
    }
};
