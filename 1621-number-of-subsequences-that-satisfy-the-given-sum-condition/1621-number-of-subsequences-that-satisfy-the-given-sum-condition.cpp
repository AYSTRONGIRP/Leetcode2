class Solution {
public:
int modExp(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp = exp / 2;
        }
        return (int)result;
    }

    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        int ans = 0 ;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int i = 0 , j = n-1;
        int half = target+1/2;
        int k = n-1;
        while(nums[k]>half){
            k--;
        }
        int count = 0 ;
        for(int i = 0 ; i< n ; i++)
            if(nums[i]<target)
                count++;
        while(i<=j){
            int sum = nums[i]+nums[j];
            if(sum>target){
                j--;
            }else{
                ans = (ans + modExp(2, j - i, MOD)) % MOD;
                i++;
                // cout<<ans<<endl;
            }
        }

        

        return ans ;
    }
};