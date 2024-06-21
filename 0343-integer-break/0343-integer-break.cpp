class Solution {
public:
    int integerBreak(int n) {
        int dp [n+1] ;
        if(n==2)
            return 1 ;
        dp[1]=1;
        dp[2]=2;
        if(n==3)
            return 2 ;
        dp[3]=3;
        for(int i = 4 ; i < n+1 ; i++){
            dp[i]=0;
            // cout<<(i+1)/2<<"half"<<i<<endl;
            for(int j = i-1 ; j >=(i+1)/2 ; j--){
                dp[i]= max(dp[i],max(dp[j]*dp[i-j],j*(i-j)));
                // if(i==8)
                // cout<<dp[j]*dp[i-j]<<"ajkd"<<j*(i-j)<<endl;
            }
        }

        // for(int i = 0 ; i <=n ; i++){
        //     cout<<dp[i]<<"  --  "<<i<<endl;
        // }

        return dp[n];
    }
};