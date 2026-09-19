class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tank = 0;
        int st = 0;
        for(int i = 0;i<n;i++){
            tank += gas[i];
            if(cost[i] > tank){
                st = i+1;
                tank = 0;
            }else{
                tank -= cost[i];
            }
        }

        tank = 0;
        for(int i = st;i<(st+n);i++){
            int idx = i%n;
            tank += (gas[idx]);
            if(cost[idx] > tank) return -1;
            tank -= cost[idx];
        }
        return st;
    }
};
