class Solution {
public:

    void bfs(vector<vector<int>>& isConnected,vector<bool>& visited ,queue<int>& q , int & l , int& n){
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            for(int i = 0 ; i <n ; i++){
                if(isConnected[top][i]==0)
                    continue;
                if(!visited[i]){
                    q.push(i);
                    visited[top]=true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int l = isConnected.size();
        int n = isConnected[0].size();

        vector<bool> visited (l,false);
        queue<int> q;
        
        int ans = 0 ;

        for(int i = 0 ; i < l; i++ ){
            if(!visited[i]){
                q.push(i);
                visited[i]=true;
                bfs(isConnected , visited , q , l , n);
                ans++;
            }
        }

        return ans;
    }
};