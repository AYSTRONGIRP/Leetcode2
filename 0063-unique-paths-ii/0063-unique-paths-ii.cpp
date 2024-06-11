class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int l = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(l == 1 && n == 1){
            if(obstacleGrid[0][0]==0)
            return 1;
            else
            return 0 ;
        }
        
        if(obstacleGrid[0][0]==0)
        obstacleGrid[0][0]=1;
        else
        obstacleGrid[0][0]=0;
        for(int i = 0 ; i < l ; i++){
            
            for(int j = 0 ; j < n ; j++){
                if(i == 0 ){
                    if(j==0)
                    continue;
                    if(obstacleGrid[i][j]!=1)
                    {if(j!=0)obstacleGrid[i][j] = obstacleGrid[i][j-1];}
                    else
                    obstacleGrid[i][j]=0;
                }
                else
                {   
                    if(i==0)
                    continue;
                    if(j==0){
                        if(obstacleGrid[i][j]!=1)
                        {if(i!=0)obstacleGrid[i][j] = obstacleGrid[i-1][j];}
                        else
                        obstacleGrid[i][j]=0;
                    }
                    else{
                        if(obstacleGrid[i][j]!=1)
                        obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1] ;
                        else
                        obstacleGrid[i][j]=0;
                    }     
                    
                }
            }
        }
        for(auto it : obstacleGrid){
            for(auto it2 :it){
                cout<<it2<<' ';
            }
            cout<<endl;
        }

        return obstacleGrid[l-1][n-1];
    }
};