class Solution {
public:
    int minInsertions(string s) {
        string s1 = s ;
        reverse(s.begin(), s.end());
        string& s2 = s ;

        int l = s1.length();
        int n = s2.length();

        int dp[l+1][n+1];

        for(int i = 0 ; i <= l ; i++){
            dp[i][0]=0;
        }
        for(int i = 0 ; i <= n ; i++)
            dp[0][i]=0;

        for(int i1 = 1 ;  i1<=l ; i1++){

            for(int i2 = 1 ; i2<= n ; i2++){

                if(s1[i1-1]==s2[i2-1]){
                    dp[i1][i2]=1+dp[i1-1][i2-1];
                }else{
                    dp[i1][i2] = max(dp[i1][i2-1],dp[i1-1][i2]);
                }

            }
        }

        // for(int i1 = 0 ;  i1<=l ; i1++){

        //     for(int i2 = 0 ; i2<= n ; i2++){

        //         cout<<dp[i1][i2]<<' ';
        //     }
        //     cout<<endl;
        // }

        return l - dp[l][n];


        // return 1;
    }
};