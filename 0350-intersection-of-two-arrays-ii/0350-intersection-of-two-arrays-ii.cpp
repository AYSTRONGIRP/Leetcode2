class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int l = nums2.size();
        vector<int> ans;

        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int prev = -1 ;
        int i = 0 , j = 0 ;
        while(i<n && j<l){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i++]);
                j++;
            }else{
                if(nums1[i]>nums2[j])
                    j++;
                else
                    i++;
            }
        }

        return ans;
    }
};