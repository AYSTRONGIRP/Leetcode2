class Solution {
public:
    int M =1e9+7;
    int count = 0 ;
    int dfs(vector<vector<vector<int>>>& dp , int m , int n , int moves , int i , int j ){
        if(i<0 || j < 0 || i==m || j==n)
            return 1;
        
        if(moves==0)
            return 0 ;

        if(dp[i][j][moves]!=-1)
            return dp[i][j][moves];
        
        dp[i][j][moves]=((dfs(dp,m,n,moves-1,i-1,j)%M+dfs(dp,m,n,moves-1,i,j-1)%M)%M+(dfs(dp,m,n,moves-1,i+1,j)%M+dfs(dp,m,n,moves-1,i,j+1)%M)%M)%M;
        
        // count+=dp[i][j][moves];

        return dp[i][j][moves];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));

        int i = dfs(dp,m , n , maxMove , startRow , startColumn);
        // cout<<count<<endl;
        return i;
    }
};