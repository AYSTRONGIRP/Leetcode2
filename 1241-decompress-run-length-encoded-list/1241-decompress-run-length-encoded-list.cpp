class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i += 2) {
            int frequency = nums[i];
            int value = nums[i + 1];
            ans.insert(ans.end(), frequency, value);
        }
        return ans;
    }
};
