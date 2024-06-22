class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count = 0;
        for(auto it: nums2){
            it = it *k ;
            for(auto it2 : nums1){
                if(it2%it==0)
                    count++;
            }
        }
        return count ;
    }
};