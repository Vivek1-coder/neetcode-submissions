class Solution {
    boolean isValid(char[][] board){
        Map<Integer,HashSet<Character>> colMp = new HashMap<>();
        Map<Integer,HashSet<Character>> rowMp = new HashMap<>();
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.') continue;
                rowMp.putIfAbsent(i,new HashSet<>());
                colMp.putIfAbsent(j,new HashSet<>());
                if(rowMp.get(i).contains(board[i][j])){
                    return false;
                }
                if(colMp.get(j).contains(board[i][j])){
                    return false;
                }
                rowMp.get(i).add(board[i][j]);
                colMp.get(j).add(board[i][j]);
            }
        }

        for(int i = 0;i<9;i+=3){
            for(int j = 0;j<9;j+=3){
                Set<Character> st = new HashSet<>();
                for(int ci=0;ci<3;ci++){
                    for(int cj = 0;cj<3;cj++){
                        int ni = i+ci;
                        int nj = j+cj;
                        if(board[ni][nj] == '.') continue;
                        if(st.contains(board[ni][nj])) return false;
                        st.add(board[ni][nj]);
                    }
                }
            }
        }
        return true;
    }
   
    public boolean isValidSudoku(char[][] board) {
       return isValid(board);

    }
}
