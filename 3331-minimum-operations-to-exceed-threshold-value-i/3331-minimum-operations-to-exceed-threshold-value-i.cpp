class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>hash;
        int count = 0 ;
        for(int i = 0 ; i < n ;i++ ){
            if(nums[i]<k )
            {
                count++;
                // hash[nums[i]]++;
            }
        }

        return count ;
    }
};