class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1){
            return nums[0];
        }
        else if (n==2){
            return max(nums[1],nums[0]);
        }

        vector <int> ans (n,-1);

        ans[0]=nums[0];
        ans[1]=nums[1];
        ans[2]=nums[0]+nums[2];

        for(int i = 3 ; i < n ; i++){
            int one = ans[i-2]+nums[i];
            int two = ans[i-3]+nums[i];
            ans[i]= max(one,two);
        }

        return max(ans[n-1],ans[n-2]);
    }
};