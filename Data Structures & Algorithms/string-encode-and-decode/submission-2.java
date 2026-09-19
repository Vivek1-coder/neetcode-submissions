class Solution {

    public String encode(List<String> strs) {
        String encoded = "";
        int n = strs.size();
        for(String curr:strs){
            int len = curr.length();
            String lenS = Integer.toString((Integer)len);
            lenS += '#';
            encoded += lenS;
            encoded += curr;
        }
        return encoded;
    }

    public List<String> decode(String str) {
        List<String> ans = new ArrayList<>();
        int idx = 0;
        int n = str.length();
        while(idx < n){
            int len = 0;
            while(str.charAt(idx) != '#'){
                int dig = (str.charAt(idx)-'0');
                len = len*10 + dig;
                idx++;
            }
            idx++;
            String curr = "";
            for(int i = 0;i<len;i++){
                curr += str.charAt(idx);
                idx++;
            }
            ans.add(curr);
        }
        return ans;
    }
}
