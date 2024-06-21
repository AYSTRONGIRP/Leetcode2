class Solution {
public:
    
    
    int n ; 
    int getAns(int ind , int buy , int cap , vector<int>& prices,vector<vector<vector<int>>>& dp) {
        if(cap==0 || ind == n )
            return 0 ;
        
        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];

        int profit = 0 ;

        if(buy==0){
            profit = max(getAns(ind+1 , 1 , cap, prices ,dp) - prices[ind],getAns(ind+1 , 0 , cap, prices ,dp));
        }

        if(buy==1){
            profit = max(getAns(ind+1 , 0 , cap-1, prices ,dp) + prices[ind],getAns(ind+1 , 1 , cap, prices ,dp));
        }

        return dp[ind][buy][cap]= profit ;
    }
    


    int maxProfit(vector<int>& prices) {
        n = prices.size();
        // ind = n ;
        vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(3, -1)));
        return getAns(0,0,2,prices,dp);
    }
};