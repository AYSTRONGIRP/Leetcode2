class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // int prefix= 0;
        int n = nums.size();
        // vector<int> ans (n,0);

        for(int i = 1 ; i < n ;i++){
            nums[i]+=nums[i-1];
            // ans[i]=prefix;
        }
        return nums;
    }
};