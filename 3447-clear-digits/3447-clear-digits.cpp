class Solution {
public:
    string clearDigits(string s) {
        int i = 0 ;// j = -1 ;
        string ans = "";
        int n = s.size();
        while(i<n){
            if(isdigit(s[i])){
                ans= ans.substr(0,ans.length()-1);
            }
            else{
                ans+=s[i];
            }
            i++;
        }

        return ans ;
    }
};