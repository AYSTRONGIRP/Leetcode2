class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long count = 0;
        unordered_map <int,int> map;
        int n = nums1.size();
        // sort(nums1.begin(), nums1.end());
        // vector<int> hash (n,-1);
        for(auto it :nums1){
            for(int i = 1 ; i*i<=it ; i++){

                if(it%i==0 && i*i==it){
                    map[i]++;
                }else if(it%i==0){
                    map[i]++;
                    map[it/i]++;
                }

            }
        }

        for(auto it: nums2){
            it = it *k ;
            // int temp = 0 ;
            // if(map.find(it)!=map.end()){
            //     count+=map[it];
            //     continue;
            // }
            
            // map[it]=temp;
            count+=map[it];
        }

        return count ;
    }
};