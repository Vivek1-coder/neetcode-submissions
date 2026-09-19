class MedianFinder {
public:
    priority_queue<pair<int,int>,vector<pair<int,int>>> maxHeap;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> minHeap;
    int sz;
    MedianFinder() {
        this->sz = 0;
    }
    
    void addNum(int num) {
        sz++;
        int left = ((sz-1)/2) + 1;
        int right = sz-left;
        
        if(maxHeap.empty() || num < maxHeap.top().first){
            maxHeap.push({num,sz});
            while(maxHeap.size() > left){
                auto [temp,i] = maxHeap.top();
                maxHeap.pop();
                minHeap.push({temp,i});
            }
        }else{
            minHeap.push({num,sz});
            while(minHeap.size() > right){
                auto [temp,i] = minHeap.top();
                minHeap.pop();
                maxHeap.push({temp,i});
            }
        }
    }
    
    double findMedian() {
        if(sz%2 == 0){
            int a = maxHeap.top().first;
            int b = minHeap.top().first;
            return (double)(a+b)/2.00;
        }
        else{
            return maxHeap.top().first;
        }
    }
};
