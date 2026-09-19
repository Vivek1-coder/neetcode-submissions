class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> row;
        unordered_map<int,unordered_set<int>> col;
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.') continue;
                int num = board[i][j]-'0';
                if(col.count(j) && col[j].count(num)){
                    return false;
                }
                if(row.count(i) && row[i].count(num)){
                    return false;
                }
                row[i].insert(num);
                col[j].insert(num);
            }
        }

        for(int i = 0;i<9;i+=3){
            for(int j = 0;j<9;j+=3){
                vector<int> mp(10,0);
                for(int r = 0;r<3;r++){
                    for(int c = 0;c<3;c++){
                        if(board[i+r][j+c] == '.') continue;
                        int num = board[i+r][j+c] - '0';
                        if(mp[num] == 1) return false;
                        mp[num] = 1;
                    }
                }
            }
        }
        return true;
    }
};
