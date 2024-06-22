class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<vector<int>> count (100+1, vector<int>());
        int n = nums.size();
        vector<int> ans (n,0);

        for(int i = 0 ; i < n ; i++){
            count[nums[i]].push_back(i);
        }

        int temp = 0; 

        for(int i = 0 ; i <=100 ; i++){
            int k = count[i].size();
            for(int j = 0 ; j < k ; j++){
                ans[count[i][j]]=temp;
            }
            temp+=k;
        }
        return ans;
    }
};