class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        sort(nums.begin(),nums.end());
        int n = nums.size();

        // vector<int> count ()
        int ans = 0 ;
        //  count = 0 ; 
        // int temp = 0 ;
        // int last = nums[n-1];
        int diff = 0 ;
        for(int i = 1  ; i < n ; i++){
            if(nums[i]<=nums[i-1])
            {
                diff = nums[i-1]-nums[i];
                nums[i]+=diff+1;
                ans += diff + 1 ;
            }
        }

        // for(auto it : nums){
        //     cout<<it<<' ';
        // }
        return ans ;
    }
};