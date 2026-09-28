class Solution {
    int findSum(int num){
        int sm = 0;
        while(num > 0){
            int dig = num%10;
            sm += (dig*dig);
            num /= 10;
        }
        return sm;
    }
    public boolean isHappy(int n) {
        Set<Integer> st = new HashSet<>();
        int num = n;
        while(!st.contains(num)){
            st.add(num);
            System.out.print(num);
            int sm = findSum(num);
            if(sm == 1) return true;
            num = sm;
        }
        return false;
    }
}
