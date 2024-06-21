class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        if(1<=stoi(s.substr(0,1)) && stoi(s.substr(0,1))<=26 && s[0]!='0'){
            cout<<stoi(s.substr(0,1))<<endl;
            dp[0]=1;
            cout<<"true 0 "<<endl;
        }else{
            dp[0]=0;
        }

        if(n==1)
            return dp[0];
        if(1<= stoi(s.substr(0,2)) && stoi(s.substr(0,2)) <=26 && s[0]!='0'){
            dp[1]=1;
            cout<<"true 1 "<< stoi(s.substr(0,2)) <<endl;
            if(1<=stoi(s.substr(1,1)) && stoi(s.substr(1,1))<=26 && s[1]!='0'){
                dp[1]+=dp[0];
                cout<<"true 11"<<endl;
            }
        }else{
            dp[1]=0;
            if(1<=stoi(s.substr(1,1))&& stoi(s.substr(1,1))<=26 && s[1]!='0'){
                dp[1]+=dp[0];
                cout<<"true 11"<<endl;
            }
        }
        

        for(int i = 2 ;i < n ; i++){
            dp[i]=0;
            if(1<=stoi(s.substr(i-1,2)) && stoi(s.substr(i-1,2))<=26 && dp[i-2]!=0 && s[i-1]!='0'){
                dp[i]+=dp[i-2];
            }
            if(1<=stoi(s.substr(i,1)) && stoi(s.substr(i,1))<=26 && dp[i-1]!=0){
                dp[i]+=dp[i-1];
            }

        }

        for(int i = 0 ; i< n ;i++){
            cout<<dp[i]<<" - "<<i<<endl;
        }

        return dp[n-1];
    }
};