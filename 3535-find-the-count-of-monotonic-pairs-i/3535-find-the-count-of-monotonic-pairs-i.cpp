#include <unordered_map>
#include <vector>
#include <utility> // For std::pair
#include <functional> // For std::hash

using namespace std;

// struct pair_hash {
//     template <class T1, class T2>
//     size_t operator()(const pair<T1, T2>& p) const {
//         auto h1 = hash<T1>{}(p.first);
//         auto h2 = hash<T2>{}(p.second);
//         return h1 ^ h2; // Combine the hash values
//     }
// };

class Solution {
public:
    const int MOD = 1e9 + 7;
    // unordered_map<pair<int, int>, int, pair_hash> dp;

    int dfs(vector<int>& nums, int a1, int a2, int index, int size , vector<vector<int>> &dp) {
        if (index == size) {
            return 1;
        }

        if (a2 < 0) {
            return 0;
        }

        if (nums[index] < a1) {
            return 0;
        }

        // auto key = make_pair(index, a1);
        // auto it = dp.find(key);

        // if (it != dp.end()) {
        //     return it->second;
        // }

        if(dp[index][a1]!=-1)
            return dp[index][a1];

        int sum = 0;
        for (int i = a1; i <= nums[index]; i++) {
            if ((nums[index] - i) <= a2)
                sum = (sum % MOD + dfs(nums, i, nums[index] - i, index + 1, size , dp) % MOD) % MOD;
        }

        // dp[key] = sum % MOD;
        dp[index][a1]=sum; 
        return sum % MOD;
    }

    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (2001 ,vector<int>(1001,-1));
        return dfs(nums, 0, INT_MAX, 0, n , dp );
    }
};
