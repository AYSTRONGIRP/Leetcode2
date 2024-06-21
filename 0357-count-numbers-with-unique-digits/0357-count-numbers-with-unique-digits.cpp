class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // cout<<pow(9,(n-1))<<endl;
        // cout<<pow(10,n)<<endl;
        // cout<<(pow(10,n)- (int)pow(9,n-1))<<endl;

        int res = 1 ;
        int temp =9 ;
        int dp[9];
        dp[1]=10; 

        for(int i = 1 ; i <= n ; i++){    
            if(i==2){
                temp++;
                res*=(temp);}
            else
            res*=(temp);
            temp--;

            if(i>1)
                dp[i] = res+dp[i-1];
            // cout<<res<<" "<<temp<<endl;
        }
        
        if(n==1)
            return 10 ;
        if(n==0)
            return 1 ;

        // for(int i = 0 ; i<=n ; i++){
        //     cout<<dp[i]<<endl;
        // }
        return dp[n];
    }
};