class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][2];

        dp[0][0]=-prices[0];
        dp[0][1]=0;

        for(int i = 1 ; i < n ; i++){
            //buy
            if(prices[i]<prices[i-1])
                dp[i][0]=dp[i-1][1]-prices[i];
            else{
                dp[i][0]=dp[i-1][0];
            }
            //sell
            if(prices[i]>prices[i-1])
                dp[i][1]=dp[i-1][0]+prices[i];
            else
                dp[i][1]=dp[i-1][1];
        }

        return dp[n-1][1];
    }
};