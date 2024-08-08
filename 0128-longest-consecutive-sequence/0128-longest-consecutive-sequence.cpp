class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        if(nums.size()==0)
            return 0 ;
        // int prev = nums[0];
        int count = 1;

        int n = nums.size();

        int maxi = 0 ;

        for(int i = 0 ; i < n-1 ; i++ ){
            if((nums[i]+1) == nums[i+1])
                count++;
            else{
                maxi = max(maxi,count);
                if(nums[i]!=nums[i+1])
                    count = 1 ;
            }
        }

        maxi = max(maxi,count);

        return maxi ;
    }
};