class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        res.push_back(vector<int>());

        for(int i = 0 ; i < n ; i++){
            int k = res.size();
            for(int j = 0 ; j < k ;j++)
            {
                vector<int>temp = res[j];
                temp.push_back(nums[i]);

                res.push_back(temp);
            }
        }

        return res ;
    }
};