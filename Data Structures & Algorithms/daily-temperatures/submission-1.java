class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Stack<Integer> st = new Stack<>();
        int [] result = new int[n];
        for(int i = 0;i<n;i++){
            result[i] = 0;
            while(!st.isEmpty() && ( temperatures[st.peek()] < temperatures[i])){
                int idx = st.pop();
                result[idx] = i-idx;
            }
            st.push(i);
        }
        return result;
    }
}
