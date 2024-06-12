class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int zero_count = 0 ;

        int sum = accumulate(nums.begin(),nums.end(),0);

        if((target+sum)%2 || (target+sum)<0)
            return 0;

        target = (target+sum)/2;

        vector<vector<int>>dp (n,vector<int>(target+1));

        for(int i = 0 ; i < n ; i++){
            dp[i][0]=1;
        }

        if(nums[0]<=target)
            dp[0][nums[0]]=1;

        if(nums[0]==0)
            {
                zero_count++;
                // continue;
            }

        for(int index = 1 ; index <n ; index++){
            if(nums[index]==0)
            {
                zero_count++;
                for(int targetC = 1 ; targetC<=target;targetC++){
                    dp[index][targetC]=dp[index-1][targetC];
                }

                continue;
            }
            for(int targetC = 1 ; targetC<=target;targetC++){
                int take = 0 ;

                if(nums[index]<=targetC){
                    take=dp[index-1][targetC-nums[index]];
                }

                int not_take = 0 ;

                not_take=dp[index-1][targetC];


                // if (take>not_take)
                //     dp[index][targetC]=take;
                // else
                    dp[index][targetC]=take+not_take;
            }
        }
        // for(auto it:nums){
        //     if()
        // }

        for(auto it : dp){
            for(auto it2: it){
                cout<<it2<<' ';
            }
            cout<<endl;
        }

        cout<<zero_count<<endl;

        if(dp[n-1][target]!=-1)
            return dp[n-1][target]*(1<<zero_count);

        return 0 ;

    }
};