class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
            int tar = -nums[i];
            while(l<r){
                if(nums[l]+nums[r] == tar){
                    ans.add(new ArrayList<Integer>(Arrays.asList(nums[i], nums[l], nums[r])));   
                    while(l<r && nums[l+1] == nums[l]){
                        l++;
                    }
                    l++;
                    r--;
                }else if(nums[l]+nums[r] > tar){
                    r--;
                }else{
                    l++;
                }
            }
        }
        return ans;
    }
}
