class Solution {
    public boolean hasDuplicate(int[] nums) {
        int n = nums.length;
        Set<Integer> mp = new HashSet<Integer>();
        for(int num:nums){
            if(mp.contains(num)) return true;
            mp.add(num);
        }
        return false;
    }
}