class Solution {
public:
    string clearStars(string s) {
        int hash[26]={0};
        int n = s.size();

        vector<int> bitAns (n,1);

        vector<vector<int>>prev (26,vector<int>());

        for(int i = 0; i < n ; i++){
            if(s[i]=='*'){
                bitAns[i]=0;
                for(int j= 0 ; j < 26 ;j++){
                    if(hash[j]>0){
                        hash[j]--;
                        bitAns[prev[j][prev[j].size()-1]]=0;
                        //remove the last element in the vector
                        prev[j].pop_back();

                        break;
                    }
                }
            }
            else{
                hash[s[i]-'a']++;
                prev[s[i]-'a'].push_back(i);
            }
            
        }

        string ans = "";
        for(int i = 0 ; i < n  ; i++){
            if(bitAns[i]==1)
                ans+=s[i];
        }
        
        return ans;
    }
};