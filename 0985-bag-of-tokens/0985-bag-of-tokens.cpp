class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0; 
        int n = tokens.size();

        int i = 0 , j = n-1;

        sort(tokens.begin(),tokens.end());

        int maxi = 0 ;
        while(i<=j){
            cout<<power<<endl;
            if(tokens[i]<=power)
            {
                ans+=1;
                power-=tokens[i];
                i++;
                maxi = max(maxi,ans);
            }else if( ans>0){
                ans-=1;
                power+=tokens[j];
                --j;
            }
            else{
                return maxi;
            }
        }

        return max(0,maxi) ;
    }
};