class Solution {
public:

    void helper(vector<vector<char>>& board, string word , int n , int l , int i , int j , int curI, bool & ans , vector<vector<bool>>&vis){
        int x[] = { 0 , 0 , -1 , +1};
        int y[] = {-1 , +1 , 0 , 0};

        if(curI==word.size()){
            ans=true;
            return;
        }

        for(int k = 0 ; k < 4 ; k++){
            // cout<<i<<j<<endl;
            if(x[k]+i< 0 || x[k]+i >= n || y[k]+j<0 || y[k]+j>=l){
                continue;
            }
            if(board[x[k]+i][y[k]+j] == word[curI] && vis[x[k]+i][y[k]+j]==false){
                if(curI==word.size()-1){
                    cout<<"done"<<endl;
                    ans=true;
                    return;
                }
                // cout<<curI<<" "<<i <<" "<<j <<endl;
                vis[x[k]+i][y[k]+j]=true;
                helper(board,word,n,l, x[k]+i , y[k]+j ,curI+1,ans , vis);
                vis[x[k]+i][y[k]+j]=false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;

        int n = board.size();
        int l = board[0].size();

        vector<vector<bool>>vis(n,vector<bool>(l,false));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < l ; j++){
                if(word[0]==board[i][j]){
                    // cout<<i<<j<<endl;
                    vis[i][j]=true;
                    helper(board, word ,n , l , i , j ,1 , ans , vis);
                    vis[i][j]=false;
                }
            }
        }

        return ans;
    }
};