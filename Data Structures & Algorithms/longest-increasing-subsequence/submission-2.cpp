class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(int num:nums){
            if(temp.empty() || num > temp.back()){
                temp.push_back(num);
            }
            else{
                int idx = lower_bound(temp.begin(),temp.end(),num) - temp.begin();
                temp[idx] =num;
            }
        }
        return temp.size();
    }
};
