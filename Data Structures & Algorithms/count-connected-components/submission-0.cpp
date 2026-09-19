class Solution {
public:
    vector<int> parent,rank;

    int findPar(int idx){
        if(idx == parent[idx]) return idx;
        return parent[idx] = findPar(parent[idx]);
    }
    void unite(int x,int y){
        x = findPar(x);
        y = findPar(y);
        if(x != y){
            if(rank[x] < rank[y]){
                parent[x] = parent[y];
            }
            else if(rank[x] > rank[y]){
                parent[y] = x;
            }
            else{
                parent[y] = x;
                rank[x]++;
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n,0);
        rank.resize(n,0);   

        for(int i = 0;i<n;i++){
            parent[i] = i;
            rank[i] = i;
        }
        for(auto &edge:edges){
            unite(edge[0],edge[1]);
        }
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            findPar(i);
            st.insert(parent[i]);
        } 
        return st.size();    
    }
};
