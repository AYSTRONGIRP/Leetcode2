class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int l = grid.size();
        int n = grid[0].size();

        if(l==1 && n==1){
            return grid[0][0];
        }

        for(int i = 1 ; i < n ; i++){
            grid[0][i] += grid[0][i-1];
        }

        for(int i = 1 ; i < l ; i++){
            grid[i][0] += grid[i-1][0];
        }

        for(int i = 1 ; i < l ; i++){
            for(int j = 1 ; j< n ; j++){
                grid[i][j]+= min(grid[i-1][j],grid[i][j-1]);
            }
        }

        return grid[l-1][n-1];
    }
};