class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();
        int res = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(s[i]=='a' || s[i]=='e' ||  s[i]=='i' ||  s[i]=='o' ||  s[i]=='u')
                res++;
        }

        if(res>0)
            return true;

        return false;
    }
};