class Solution {
    int solve(int a,int b,String opr){
        if(opr.equals("+")){
            return a+b;
        }else if(opr.equals("-")){
            return a-b;
        }else if(opr.equals("*")){
            return a*b;
        }else{
            return a/b;
        }
    }
    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();
        for(String token:tokens){
            if(token.equals("+") || token.equals("-") || token.equals("*") || token.equals("/")){
                int b = st.peek();
                st.pop();
                int a = st.peek();
                st.pop();
                int val = solve(a,b,token);
                st.push(val);
            }else{
                int val = Integer.parseInt(token);
                st.push(val);
            }
        }
        return st.peek();
    }
}
