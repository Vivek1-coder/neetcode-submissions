class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int n = strs.length;
        String[] sortedArr = new String[n];
        for(int i = 0;i<n;i++){
            char[] arr = strs[i].toCharArray();
            Arrays.sort(arr);
            sortedArr[i] = new String(arr);
        }

        Map<String,ArrayList<String>> mp = new HashMap<>();
        for(int i = 0;i<n;i++){
            mp.computeIfAbsent(sortedArr[i], k -> new ArrayList<>()).add(strs[i]);
        }

        List<List<String>> ans = new ArrayList<>();
        for(Map.Entry<String,ArrayList<String>> entry:mp.entrySet()){
            ans.add(entry.getValue());
        }
        return ans;
    }
}
