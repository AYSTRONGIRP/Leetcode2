class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        deque<int> deq;
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (!deq.empty() && deq.back() + 1 == nums[i]) {  

                deq.push_back(nums[i]);

                if (deq.size() == k) {
                    if(i>=(k-1))
                        ans.push_back(nums[i]);
                    deq.pop_front();  
                } else {
                    if(i>=(k-1))
                        ans.push_back(-1);
                }

            } else {
                deq.clear();
                deq.push_back(nums[i]);
                if (deq.size() == k) {
                    if(i>=(k-1))
                        ans.push_back(nums[i]);
                    deq.pop_front();  
                } else {
                    if(i>=(k-1))
                        ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};
