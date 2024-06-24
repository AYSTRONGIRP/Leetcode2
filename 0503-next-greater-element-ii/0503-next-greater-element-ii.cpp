class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st ;
        int n = nums.size();

        for(int i = n-1 ; i>=0 ; i--){
            // while(!st.empty() && st.top()<=nums[i]){
            //     st.pop();
            // }
            st.push(nums[i]);
        }

        for(int i = n-1 ; i>=0 ; i--){

            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }

            int prev = nums[i];
            if(st.empty())
                nums[i]=-1; 
            else
                nums[i]=st.top();
            
            st.push(prev);
        }

        // for(auto it: nums){
        //     cout<<it<<' ';
        // }

        return nums ;
    }
};