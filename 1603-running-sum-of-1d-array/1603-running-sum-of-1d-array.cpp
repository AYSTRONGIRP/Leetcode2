class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int prefix= 0;
        int n = nums.size();
        vector<int> ans (n,0);

        for(int i = 0 ; i < n ;i++){
            prefix+=nums[i];
            ans[i]=prefix;
        }
        return ans;
    }
};