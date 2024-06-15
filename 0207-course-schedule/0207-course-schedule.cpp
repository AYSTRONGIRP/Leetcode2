class Solution {
public:
    void dfs(int curr , set<int> &parent,vector<int>& visited,vector<vector<int>>& adj, stack<int>& st,bool & flag){
        
        // if(visited[curr]==1 && curr==parent)
        //     flag = false ;
        
        visited[curr]=1;
        // if(stack.size()>)

        for(auto it : adj[curr]){
            if(!visited[it])
                {parent.insert(it);
                dfs(it ,parent,visited , adj , st , flag);
                parent.erase(it);}
            else{
                if(parent.find(it)!=parent.end())
                    flag = false ;
            }
        }
        st.push(curr);

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int l = prerequisites.size();
        // int n = prerequisites[0].size();

        if(l==0)
            return true;

        // int vistied[numCourses] = {0};
        vector<int> visited(numCourses,0);

        stack<int>st;

        vector<vector<int>> adj (numCourses,vector<int>());

        for(int i = 0 ; i < l ; i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        set<int>parent;

        bool flag = true ;

        for(int i = 0 ; i < numCourses ; i++){
            if(!visited[i]){
                parent.insert(i);
                dfs(i,parent , visited,adj,st, flag);
                parent.erase(i);
            }
        }

        // vector<int> ans;
		// while (!st.empty()) {
		// 	ans.push_back(st.top());
		// 	st.pop();
		// }



        //     for(auto it2: ans){
        //         cout<<it2<<' ';
        //     }
        //     cout<<endl;

        // for(auto it : adj){
        //     for(auto it2: it){
        //         cout<<it2<<' ';
        //     }
        //     cout<<endl;
        // }

        // cout<<"endl";
        return flag ;
    }
};