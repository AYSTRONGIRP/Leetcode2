class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        unordered_map<int,int> visited;
        vector<int> ans;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            ans.insert(ans.begin()+index[i],nums[i]);
        }

        return ans;
    }
};