class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!binary_search(nums.begin(),nums.end(),target))
            return {-1,-1};
        return {
        static_cast<int>(lower_bound(nums.begin(), nums.end(), target) - nums.begin()),
        static_cast<int>(upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1)
    };
        // return {lower_bound(nums.begin(),nums.end(),target)-nums.begin(),upper_bound(nums.begin(),nums.end(),target)-nums.begin()};
    }
};