class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        // vector<vector<int>> dp(n , vector<int>(target+1,-1));

        // for(int i = 0 ; i < n ; i++)
        //     dp[i][0]=1;
        
        // for(int i = nums[0] ; i <= target ; i+=nums[0]){
        //     dp[0][i]=1;
        // }

        vector<unsigned long long>dp (target+1,-1);
        dp[0]=1;

        for(int i = 1 ;i <= target ; i++){
            for(int j = 0 ; j < n ; j++ )
            {
                if(i-nums[j]>=0 && dp[i-nums[j]]!=-1){
                    if(dp[i]==-1)
                        dp[i]=0;

                    dp[i]+=dp[i-nums[j]];
                }
            }
        }

        // for(auto it: dp){
            for(auto it2:dp){
                cout<<it2<<' ';
            }
        //     cout<<endl;
        // }
        if(dp[target]==-1)
            return 0 ;

        return dp[target];
    }
};