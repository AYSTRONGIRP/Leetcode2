class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp (n+1,(vector<int>(n+1,0)));

        // cout<<n<<"sieze"<<endl;
        // cout<<dp.size()<<dp[0].size()<<endl;

        for(int ind = n-1 ; ind>=0 ; ind--){
            for (int prev_ind = ind ; prev_ind>= 0 ; prev_ind--){
                int take = 0;

                if(prev_ind==0 || nums[ind]>nums[prev_ind-1]){
                    take = 1 + dp[ind+1][ind+1];
                }
                int not_take = 0;

                not_take = 0 + dp[ind+1][prev_ind];

                dp[ind][prev_ind] = max(take,not_take);
            }
        }

        // for(auto it : dp){
        //     for(auto it2: it){
        //         cout<<it2<<' ';
        //     }
        //     cout<<endl;
        // }

        return dp[0][0];

    }
};
