class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int st = 0;
        int end = n-1;
        while(st < end){
            for(int i = 0;i<n;i++){
                int temp = matrix[st][i];
                matrix[st][i] = matrix[end][i];
                matrix[end][i] = temp;
            }
            st++;
            end--;
        }

        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp; 
            }
        }
        
    }
}
