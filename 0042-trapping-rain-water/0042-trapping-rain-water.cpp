class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lb[n];
        int rb[n];

        stack <int>st ;
        for(int i = 0 ; i< n ; i++){
            while(!st.empty() && height[st.top()]<height[i])
                st.pop();
            if(st.empty()){
                lb[i]=0;
                st.push(i);
            }else{
                lb[i]=height[st.top()];
            }
            // st.push(i);
        }

        while(!st.empty()){
            cout<<st.top()<<' ';
            st.pop();
        }

        for(int i = n-1 ; i>=0 ; i--){
            while(!st.empty() && height[st.top()]<height[i])
                st.pop();

            if(st.empty()){
                rb[i]=0;
                st.push(i);
            }else{
                rb[i]=height[st.top()];
            }
            // st.push(i);
        }

        // while(!st.empty()){
        //     cout<<st.top()<<' ';
        //     st.pop();
        // }
        // cout<<endl;
        // for(int i = 0 ; i < n ; i++){
        //     cout<<lb[i]<<' ';
        // }
        // cout<<endl;
        // for(int i = 0 ; i < n ; i++){
        //     cout<<rb[i]<<' ';
        // }
        int ans = 0 ;
        int h = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(lb[i]>rb[i])
                h=rb[i];
            else
                h=lb[i];
            
            if(height[i]<h)
                ans += (h-height[i]);
        }

        return ans ;
    }
};