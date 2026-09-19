class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int str = 0;
        int stc = 0;
        int endr = matrix.size()-1;
        int endc = matrix[0].size()-1;

        vector<int> ans;
        while(true){
            for(int j = stc;j<=endc;j++){
                ans.push_back(matrix[str][j]);
            }
            str++;
            if(str > endr) break;
            for(int i = str;i<=endr;i++){
                ans.push_back(matrix[i][endc]);
            }
            endc--;
            if(stc > endc) break;
            for(int j = endc;j>=stc;j--){
                ans.push_back(matrix[endr][j]);
            }
            endr--;
            if(str > endr) break;
            for(int i = endr;i>=str;i--){
                ans.push_back(matrix[i][stc]);
            }
            stc++;
            if(stc > endc) break;
        }
        return ans;
    }
};
