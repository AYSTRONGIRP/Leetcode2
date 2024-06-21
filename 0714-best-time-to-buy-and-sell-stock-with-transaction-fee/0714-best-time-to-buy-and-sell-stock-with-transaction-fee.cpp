class Solution {
public:
    int n ; 
    int getAns(int ind , int buy , int cap , vector<int>& prices,vector<vector<int>>& dp) {
        if(ind == n )
            return 0 ;
        
        if(dp[ind][buy]!=-1)
            return dp[ind][buy];

        int profit = 0 ;

        if(buy==0){
            profit = max(getAns(ind+1 , 1 , cap, prices ,dp) - prices[ind],getAns(ind+1 , 0 , cap, prices ,dp));
        }

        if(buy==1){
            profit = max(getAns(ind+1 , 0 , cap, prices ,dp) + prices[ind] - cap,getAns(ind+1 , 1 , cap, prices ,dp));
        }

        return dp[ind][buy]= profit ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();

        vector<vector<int>> dp (n , vector<int> (2,-1));

        return getAns(0 , 0 , fee , prices, dp);
    }
};