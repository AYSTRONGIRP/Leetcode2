class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0 ;
        for(auto it:arr){
            if(it&1){
                count++;
                if(count==3)
                    return true;
            }
            else
                count=0 ;
        }
        return false;
    }
};