class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 1 , j = n-2 ;

        while(i<n && j>= 0){
            if(nums[i]%2==0)
                {
                    swap(nums[i],nums[j]);
                    j-=2;
                }
            else{
                i+=2;
            }

        }
        return nums;
    }
};