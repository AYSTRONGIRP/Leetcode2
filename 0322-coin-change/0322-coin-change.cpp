class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Your code here
        int n = coins.size();
        sort(coins.begin(),coins.end());
        int W = amount ;

        vector<vector<int>> dp (n , vector<int>(W + 1,-1));
        
        for(int i = 0 ; i< n ; i++){
            dp[i][0]=0;
        }

        for(int j = 1 ; j*coins[0] <= W ; j++){

            dp[0][(j*coins[0])]=j;

        }
        
        // if(wt[0]<=W)
        //     dp[0][coins[0]]=1;
        
        int sum = W ;
        // int target = sum ;
        // int max = INT_MIN ;
        
        for(int index = 1 ; index < n ; index++){
            // if(coins[index]<=W)
            // dp[index][coins[index]]=1;
            for(int target = 1 ; target <=W ; target++){
                
                int take = -1 ;
                
                if(target-coins[index]>=0){
                    int prev_min_coin = dp[index-1][target-coins[index]];
                    if(prev_min_coin!=-1)
                        take =  1 + prev_min_coin;
                }

                int same_take = -1;
                if(target-coins[index]>=0){
                if(dp[index][target-coins[index]]!=-1)
                same_take = 1 + dp[index][target-coins[index]];
                }
                
                if(take!=-1 && take < same_take )
                    dp[index][target]=take;
                else if(same_take != -1 )
                    dp[index][target]=same_take;
                else
                    dp[index][target]=dp[index-1][target];

                if(dp[index-1][target]<dp[index][target] && dp[index-1][target]!=-1)
                    dp[index][target]=dp[index-1][target];
            }
        }
        
        // for(auto it : dp){
        //     for(auto it2: it){
        //         cout<<it2<<' ';
        //     }
        //     cout<<endl;
        // }

        return dp[n-1][W];

        // return *max_element(dp[n-1].begin(),dp[n-1].end());
    }
};