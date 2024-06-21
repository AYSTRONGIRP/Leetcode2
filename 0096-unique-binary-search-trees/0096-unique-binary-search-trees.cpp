class Solution {
public:
    int numTrees(int n) {
        int dp [n+1];
        dp[1]=1;
        dp[0]=1;
        // cout<<dp[0];
        if(n==1)
            return 1;
        
        dp[2]=2;
        
        for(int i = 3 ; i < n+1 ; i++){
            dp[i]=0;
            for(int j = i-1 ; j>=0 ; j--)
                {
                    // if(2*j==i-1)
                        dp[i]= dp[i] + dp[j]*dp[i-j-1];
                    // else
                        // dp[i]= dp[i] + 2*dp[j]*dp[i-j-1];
                }
        }

        for(int i = 0 ; i < n+1 ; i++)
        {
            cout<<dp[i]<<endl;
        }

        return dp[n];
    }
};