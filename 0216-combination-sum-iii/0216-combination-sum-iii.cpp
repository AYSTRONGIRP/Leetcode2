class Solution {
public:

    void backtracking(vector<vector<int>>& res ,vector<int>&comb ,int curr ,int k , int target){
        if(target<0 || curr>9){
            if(k==0 && target==0)
                res.push_back(comb);
            return ;
        }

        backtracking(res,comb,curr+1,k,target);
        comb.push_back(curr);
        backtracking(res,comb,curr+1,k-1,target-curr);
        comb.pop_back();


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res ;
        vector<int>comb ;
        backtracking(res,comb,1 ,k,n);
        return res;
    }
};