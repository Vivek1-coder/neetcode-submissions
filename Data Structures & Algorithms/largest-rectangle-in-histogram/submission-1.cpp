class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        for(int i = 0;i<=n;i++)
        {
            while((!st.empty()) && ((i == n) || (heights[st.top()] >= heights[i])))
            {
                int idx = st.top();
                st.pop();
                int prev = (st.empty())?-1:st.top();
                int area = heights[idx]*(i-prev-1);
                ans = max(ans,area);
            }
            st.push(i);
        }

        return ans;
    }
};
