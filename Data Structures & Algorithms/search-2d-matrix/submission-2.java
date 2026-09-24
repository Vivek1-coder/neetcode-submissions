class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;

        int st = 0;
        int end = m*n - 1;
        while(st <= end){
            int mid = (st+end)/2;
            int r = mid/m;
            int c = mid%m;
            if(matrix[r][c] == target){
                return true;
            }else if(matrix[r][c] > target){
                end = mid-1;
            }else{
                st = mid+1;
            }
        }
        return false;
    }
}
