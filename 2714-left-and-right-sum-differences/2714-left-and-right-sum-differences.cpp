class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        int dpl[n];
        dpl[0]=0;

        for(int i = 1 ; i< n ; i++){
            dpl[i]=nums[i-1]+dpl[i-1];
        }

        int dpr[n];
        dpr[n-1]=0;

        for(int i = n-2 ; i>=0 ; i--){
            dpr[i]=nums[i+1]+dpr[i+1];
        }

        for(int i = n-1 ; i>= 0 ; i--){
            nums[i]=abs(dpl[i]-dpr[i]);
        }

        return nums;
    }
};