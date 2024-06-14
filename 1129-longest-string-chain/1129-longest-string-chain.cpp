class Solution {
public:

    bool static compare(string& s1 , string& s2){
        return s1.size()<s2.size();
    }

    bool successor(string& s1 , string& s2){
        int i1 = s1.size();
        int i2 = s2.size();

        if(i2+1!=i1)
            return false ;

        int i = 0 , j = 0 ;

        while(i<i1){

            

            if(s1[i]==s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }

        if(i==i1 && j ==i2){
            return true;
        }

        cout<<s1 <<" false " <<s2 <<endl;

        return false ;
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end() , compare);
        int n = words.size();

        vector<int> dp(n,1);
        int max = 1 ;

        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j< i ; j++){
                if(successor(words[i],words[j]) && dp[i]<dp[j]+1){
                    // if(dp[i])
                    dp[i]=dp[j]+1;

                    if(dp[i]>max)
                        max =dp[i];
                }
            }
        }

        // for(auto it : words){
        //     cout<<it<<' ';
        // }

        return max ;

    }
};