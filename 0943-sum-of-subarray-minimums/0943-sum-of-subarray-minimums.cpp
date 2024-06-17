class Solution {
public:
    const int mod = 1e9+7 ;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int dp[n];
        stack<int> st ;
        int ans = 0 ;

        // int mod = 

        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            
            if(st.empty()){
                dp[i]=arr[i]*(i+1);
                ans=(ans+dp[i])%mod;
            }else{
                dp[i]= dp[st.top()] + (i-st.top()) * arr[i];
                ans=(ans+dp[i])%mod;
            }

            st.push(i);
        }
        // for
        return ans ;
    }
};