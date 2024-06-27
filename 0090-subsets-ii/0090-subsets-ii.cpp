class Solution {
public:

    void backtracking(vector<vector<int>>&res,vector<int>temp,vector<int>&nums,int curr , int size){
        // if(curr==size){
            res.push_back(temp);
        //     return ;
        // }
        for(int nextCurr = curr; nextCurr < size ;++nextCurr ){
            if(nextCurr>curr && nums[nextCurr]==nums[nextCurr-1]){
                continue;
            }
            //take
            temp.push_back(nums[nextCurr]);
            backtracking(res,temp,nums,nextCurr+1,size);
            temp.pop_back();
            //not take
            // backtracking(res,temp,nums,nextCurr+1,size);
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res ;
        vector<int>temp ;
        int n = nums.size();

        sort(nums.begin(),nums.end());
        backtracking(res , temp , nums , 0 , n);

        return res;
    }
};