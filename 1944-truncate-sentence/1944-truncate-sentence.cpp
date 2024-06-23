class Solution {
public:
    string truncateSentence(string s, int k) {
        int n = s.size()    ;
        int count = 0 ;

        for(int i = 0 ; i < n ; i++){
            if(s[i]==' ')
                count++;
            
            if(count==k)
                return s.substr(0,i);
        }

        return s ;
    }
};