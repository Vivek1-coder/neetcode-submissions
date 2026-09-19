class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int k = (m+n)/2;
        int st = 0;
        int end = min(k,m);

        while(st <= end){
            int mid1 = (st+end)/2;
            int mid2 = k-mid1;
            int prev1 = (mid1-1 >= 0)?nums1[mid1-1]:INT_MIN;
            int prev2 = (mid2-1 >= 0)?nums2[mid2-1]:INT_MIN;
            int curr1 = (mid1 < m && mid1 >= 0)?nums1[mid1]:INT_MAX;
            int curr2 = (mid2 < n && mid2 >= 0)?nums2[mid2]:INT_MAX;
            if(prev1 <= curr2 && prev2 <= curr1){
                if((m+n)%2 == 0){
                    int a = max(prev1,prev2);
                    int b = min(curr1,curr2);
                    double ans = ((double)(a+b))/2;
                    return ans;
                }
                else{
                    return min(curr1,curr2);
                }
            }
            else if(prev1 > curr2){
                end = mid1-1;
            }
            else{
                st = mid1+1;
            }
            // [1,3,5,7]
            // [2,3,4,5,6]

        }
        return -1;
    }
};
