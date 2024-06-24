class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> hash (1e4+1 , -1);
        int n2 = nums2.size();
        int n1 = nums1.size();
        stack<int> st;
        // st.push(-1);

        for(int i = n2-1 ; i >= 0 ; i--){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                st.pop();
            }
            if(st.empty())
                hash[nums2[i]]=-1; 
            else
                hash[nums2[i]]=st.top();
            st.push(i);
        }

        for(int i = 0 ; i< n1 ;i++){
            if(hash[nums1[i]]==-1)
            nums1[i]=hash[nums1[i]];
            else
            nums1[i]=nums2[hash[nums1[i]]];

        }

        return nums1;
    }
};