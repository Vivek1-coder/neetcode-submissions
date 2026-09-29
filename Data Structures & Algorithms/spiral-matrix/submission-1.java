class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int stR = 0,stC = 0;
        int endR = m-1,endC = n-1;
        List<Integer> ans = new ArrayList<>();
        while(stR <= endR && stC <= endC){
            for(int idx = stC;idx<=endC;idx++){
                ans.add(matrix[stR][idx]);
            }
            stR++;
            if(stR > endR) break;
            for(int idx = stR;idx<=endR;idx++){
                ans.add(matrix[idx][endC]);
            }
            endC--;
            if(stC > endC) break;
            for(int idx = endC;idx >=stC;idx--){
                ans.add(matrix[endR][idx]);
            }
            endR--;
            if(stR > endR) break;
            for(int idx = endR;idx >= stR;idx--){
                ans.add(matrix[idx][stC]);
            }
            stC++;
        }
        return ans;
    }
}
