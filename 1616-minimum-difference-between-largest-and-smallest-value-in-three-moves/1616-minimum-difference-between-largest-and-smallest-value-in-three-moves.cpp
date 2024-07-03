class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        if(nums.size()<5)
            return 0 ;
        
        int i = 0 ; int j = nums.size()-1;
        int ix[4] = {0,1,2,3};
        int jx[4] =  {3,2,1,0};
        int mini = INT_MAX;

        for(int k = 0 ; k<= 3 ; k++){
            // cout<<nums[nums.size()-1-nums[jx[k]]]<<endl;
            mini= min(mini,(nums[nums.size()-1-jx[k]] - nums[ix[k]]));
        }

        return mini;
    }
};