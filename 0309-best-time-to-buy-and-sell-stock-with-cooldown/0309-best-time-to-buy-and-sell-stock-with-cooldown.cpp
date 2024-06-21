class Solution {
public:
    int n;
    int getAns(int ind, int buy, int cap, vector<int>& prices,
               vector<vector<vector<int>>>& dp) {
        if (ind == n)
            return 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        int profit = 0;

        if (cap == 1) {
            return dp[ind][buy][cap] = getAns(ind + 1, 0, 0, prices, dp);
        }

        if (buy == 0) {
            profit = max(getAns(ind + 1, 1, 0, prices, dp) - prices[ind],
                         getAns(ind + 1, 0, 0, prices, dp));
        }

        if (buy == 1) {
            profit = max(getAns(ind + 1, 0, 1, prices, dp) + prices[ind],
                         getAns(ind + 1, 1, cap, prices, dp));
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        // ind = n ;
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1)));
        return getAns(0, 0, 0, prices, dp);
    }
};