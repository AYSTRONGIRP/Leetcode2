class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 1 ; 
        int r = n-2 ;
        if(nums[0]<nums[n-1] || n == 1)
            return nums[0];
        if(n==2)
            return min(nums[0],nums[1]);
        
        if(nums[0]<nums[n-1] && nums[0]<nums[1]){
            return nums[0];
        }
        if(nums[n-1]<nums[0] && nums[n-1]<nums[n-2]){
            return nums[n-1];
        }
        
        while(l<=r){
            long mid = l+(r-l)/2;
            cout<<mid<<"mid"<<endl;
            cout<<l<<"l h"<<r<<endl;
            if(nums[mid]<nums[mid-1] &&nums[mid]<nums[mid+1])
                return nums[mid];
            else if(nums[mid]<nums[n-1])
                    r=mid-1;
            else
                    l=mid+1;
        }

        return 0;

    }
};