class MinStack {
    Stack<int []> st = new Stack<>();
    public MinStack() {
        
    }
    
    public void push(int val) {
        int mini = (st.isEmpty())?val:Math.min(st.peek()[1],val);
        st.push(new int[]{val,mini});
    }
    
    public void pop() {
        st.pop();        
    }
    
    public int top() {
        return st.peek()[0];
    }
    
    public int getMin() {
        return st.peek()[1];
    }
}
