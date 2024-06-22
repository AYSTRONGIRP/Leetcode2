class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int count = 0;
        for(string s :sentences){
            int n = s.length();
            int temp = 0 ; 
            for(char ch : s){
                if(ch==' ')
                    temp++;
            }
            count = max(count,temp+1);
        }
        return count;
    }
};