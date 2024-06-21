class Solution {
public:
    bool divisorGame(int n) {
        int dp[1000+1];
        dp[1]= 0 ;
        dp[2]= 1 ;

        for(int i = 3 ; i <= n ; i++){
            for(int j = i-1 ; j>=1 ; j--){
                if(i%j==0 ){
                    if(dp[i-j]==0)
                    {dp[i]=1;break;}
                    else
                    dp[i]=0;
                }
            }
        }

        for(int i = 0 ; i< n ; i++){
            cout<<i<<"--"<<dp[i]<<endl;
        }
        return dp[n];
    }
};