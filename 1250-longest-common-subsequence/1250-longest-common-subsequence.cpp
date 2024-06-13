class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l = text1.length();
        int n = text2.length();

        int dp[l+1][n+1];

        for(int i = 0 ; i <= l ; i++){
            dp[i][0]=0;
        }
        for(int i = 0 ; i <= n ; i++)
            dp[0][i]=0;

        for(int i1 = 1 ;  i1<=l ; i1++){

            for(int i2 = 1 ; i2<= n ; i2++){

                if(text1[i1-1]==text2[i2-1]){
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

        return dp[l][n];
    }
};