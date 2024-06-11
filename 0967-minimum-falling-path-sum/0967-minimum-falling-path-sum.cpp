class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=INT_MAX;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int x=matrix[i-1][j];
                if(j+1<m) x=min(x,matrix[i-1][j+1]);
                if(j-1>=0) x=min(x,matrix[i-1][j-1]);
                matrix[i][j]+=x;
            }
        }
        for(int i=0;i<m;i++) ans=min(ans,matrix[n-1][i]);
        return ans;
    }
};