class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i = 1 ;  i<= n ; i++){
            int countBit = 0 ; 
            int j = 0 ;
            while(i-1 & 1<<j){
                j++;
            }
            dp[i]=dp[i-1]+(1-j);
        }

        return dp;
    }
};