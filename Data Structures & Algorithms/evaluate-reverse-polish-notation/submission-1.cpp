class Solution {
public:
    int eval(int a,int b,char opr){
        if(opr == '+'){
            return a+b;
        }
        else if(opr == '-'){
            return a-b;
        }
        else if(opr == '*'){
            return a*b;
        }
        else{
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        int n =tokens.size();
        stack<int> st;
        for(int i = 0;i<n;i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || 
            tokens[i] == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int ans  = eval(a,b,tokens[i][0]);
                st.push(ans);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
