class KthLargest {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
    int k;
    int idx;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;  
        this->idx = 0;
        for(int num:nums){
            int t = add(num);
        }
    }
    
    int add(int val) {
        minHeap.push({val,idx});
        idx++;
        if(minHeap.size() > k){
            minHeap.pop();
        }   
        return minHeap.top().first;
    }
};
