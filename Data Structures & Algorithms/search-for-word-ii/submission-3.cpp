class Node{
    public:
        vector<Node*> children;
        bool terminal;
        bool inserted;
        Node(){
            this->children.resize(26);
            for(int i = 0;i<26;i++){
                this->children[i] = nullptr;
            }
            this->terminal = false;
            this->inserted = false;
        }
};


class Solution {
public:
    Node* root;
    vector<pair<int,int>> dirs = {
        {-1,0},{1,0},{0,1},{0,-1}
    };

    void search(vector<vector<char>>& board,int r,int c,Node* temp,vector<string> &ans,
    string s){
        char ch = board[r][c];
        board[r][c] = '#';
        if(temp->terminal && !temp->inserted){
            ans.push_back(s);
            temp->inserted = true;
        }

        for(auto [dx,dy]:dirs){
            int nx = r+dx;
            int ny = c+dy;
            if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() 
            && board[nx][ny] != '#' && 
            (temp->children[board[nx][ny]-'a'] != nullptr)){
                search(board,nx,ny,temp->children[board[nx][ny]-'a'],ans,
                s+board[nx][ny]);
            }
        }
        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->root = new Node();
        for(string &word:words){
            Node* temp = root;
            for(char ch:word){
                if(temp->children[ch-'a'] == nullptr){
                    temp->children[ch-'a'] = new Node();
                }
                temp = temp->children[ch-'a'];
            }
            temp->terminal = true;
        }

        vector<string> ans;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                int idx = board[i][j]-'a';
                if(root->children[idx] != nullptr){
                    Node* temp = root;
                    string s = "";
                    search(board,i,j,temp->children[idx],ans,s+board[i][j]);
                }
            }
        }
        return ans;
    }
};
