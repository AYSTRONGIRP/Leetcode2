class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        int N = cuts.size();

        vector<vector<int>> dp (N ,vector<int> (N, 0) );

        // cout<<"size"<<N<<endl;

        // for(auto it2: cuts){
        //     cout<<it2<<' ';
        // }
        // cout<<endl;
        for(int i = N-2 ; i >= 1 ; i-- ){

            for(int j = 1 ; j <= N-2 ; j++){
                int mini = INT_MAX;
                if(i>j)
                continue;
                for(int k = i ; k<=j ; k++){
                    // if(k>n-1)
                    // cout<<k <<j ;
                    int steps = cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    // cout<<"steps"<<steps<<' '<<cuts[j]-cuts[i]<<' '<<dp[i][k]<<' '<<dp[k][j]<<' '<<i <<' '<< k <<' '<< j <<' ' <<endl;
                    if(mini>steps)
                        mini=steps;
                }
                dp[i][j]=mini;
            }
        }

        // for(auto it : dp){
        //     for(auto it2: it){
        //         cout<<it2<<' ';
        //     }
        //     cout<<endl;
        // }

        return dp[1][N-2];
    }
};