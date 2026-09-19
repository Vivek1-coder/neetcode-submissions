class Solution {
public:
    string sum(string ans,string currLevel){
        string temp = "";
        int carry = 0;
        reverse(ans.begin(),ans.end());
        reverse(currLevel.begin(),currLevel.end());
        int n = ans.size();
        int m = currLevel.size();
        int i = 0,j = 0;
        while(i<n && j<m){
            int curr = (int)(ans[i]-'0') + (int)(currLevel[j]-'0');
            curr += carry;
            int dig = curr%10;
            temp += ('0'+dig);
            carry = curr/10;
            i++;
            j++;
        }
        while(i<n){
            int curr = (int)(ans[i]-'0');
            curr += carry;
            int dig = curr%10;
            temp += ('0'+dig);
            carry = curr/10;
            i++;
        }
        while(j<m){
            int curr = (int)(currLevel[j]-'0');
            curr += carry;
            int dig = curr%10;
            temp += ('0'+dig);
            carry = curr/10;
            j++;
        }
        while(carry > 0){
            int dig = carry%10;
            carry /= 10;
            temp += ('0'+dig);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    string multiply(string nums1, string nums2) {
        int m = nums1.size();
        int n = nums2.size();
        string ans = "";
        string zeros = "";
        for(int i = m-1;i>=0;i--){
            int mult = nums1[i]-'0';
            int carry = 0;
            string currLevel = "";
            for(int j = n-1;j>=0;j--){
                int curr = (nums2[j]-'0');
                curr *= mult;
                curr += carry;

                int dig = curr%10;
                carry = curr/10;
                currLevel += ('0'+dig);
            }
           
            while(carry > 0){
                int dig = carry%10;
                carry /= 10;
                currLevel += ('0'+dig);
            }
            reverse(currLevel.begin(),currLevel.end());
             currLevel += zeros;
            zeros += '0';
            if(ans == ""){
                ans = currLevel;
                // cout<<currLevel<<endl;
                continue;
            }
           
            // cout<<currLevel<<endl;
            ans = sum(ans,currLevel);
        }
        int i = 0;
        int ansSize = ans.size();
        while(i<ans.size() && ans[i] == '0'){
            i++;
        }
        if(i == ans.size()) return "0";
        return ans.substr(i,ansSize-i);
    }
};
