class Solution {
public:
    void helper(vector<int>& candidates, int target, int ind,
                vector<vector<int>>& res, vector<int>& combination) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;  // skip duplicates
            }
            if (candidates[i] <= target) {
                combination.push_back(candidates[i]);
                helper(candidates, target - candidates[i], i + 1, res,
                       combination);
                combination.pop_back();  // backtrack
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        helper(candidates, target, 0, res, combination);
        return res;
    }
};