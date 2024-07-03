class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        if(nums.size()<5)
            return 0 ;
        
        int i = 0 ; int j = nums.size()-1;
        // int ix[4] = {0,1,2,3};
        // int jx[4] =  {3,2,1,0};
        // int mini = INT_MAX;

        int n = nums.size();
        int mini = INT_MAX;

        // Check the minimum difference by removing different sets of 3 elements
        mini = std::min(mini, nums[n - 1] - nums[3]); // Remove the 3 smallest
        mini = std::min(mini, nums[n - 2] - nums[2]); // Remove the 2 smallest and 1 largest
        mini = std::min(mini, nums[n - 3] - nums[1]); // Remove the 1 smallest and 2 largest
        mini = std::min(mini, nums[n - 4] - nums[0]); // Remove the 3 largest


        return mini;
    }
};