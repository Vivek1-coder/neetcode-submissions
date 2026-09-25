class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        Map<String,List<String>> mp = new HashMap<>();
        for(int i = 0;i<n;i++){
            String str = strs[i];
            char[] strArr = str.toCharArray();
            Arrays.sort(strArr);
            String sorted = new String(strArr);
            mp.computeIfAbsent(sorted,k -> new ArrayList<>()).add(str);
        }
        List<List<String>> ans = new ArrayList<>();
        mp.forEach((key,val)->{
            ans.add(val);
        });
        return ans;
    }
}
