class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0 ;
        int n = nums.size();


        for(auto it : nums){
            sum+=it;
        }

        if(sum%2)
            return false;

        cout<<sum<<endl;
        int target = sum/2;
        cout<<target<<endl;

        vector<bool> prev (target+1,false);
        prev[0]=true;
        
        if(nums[0]<=target)
            prev[nums[0]]=true;

        for(int index = 1 ; index < n ; index++){
            vector<bool> curr (target+1,false);
            curr[0]=true;
            for(int targetc = 1 ; targetc <= target ; targetc++){
                bool take = false;

                if(targetc-nums[index]>=0)
                    take = prev[targetc-nums[index]];

                bool not_take = prev[targetc];

                if(take || not_take)
                    curr[targetc]=true;
                else
                    curr[targetc]=false;

            }
            prev = curr ;

        }
        return prev[target];
    }
};