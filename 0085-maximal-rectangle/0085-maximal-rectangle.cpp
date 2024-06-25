class Solution {
public:
    int maxi = 0 ;
    void area(vector<int>& heights){
        int n = heights.size();
        vector<int>rboundary(n,0);

        stack<int> st ;
        for(int i =n-1 ; i >0 ;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())
            rboundary[i]=st.top()-1;
            else
            rboundary[i]=i;
            st.push(i);
        }
        vector<int>lboundary(n,0);

        for(int i =0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty())
            lboundary[i]=st.top()+1;
            else
            lboundary[i]=i;
            st.push(i);
        }


        for(int i = 1 ; i< n-1 ;i++){
            maxi = max(maxi ,heights[i]*(rboundary[i]-lboundary[i]+1));
        }


    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int l = matrix[0].size();
        vector<int> heights (l+2,0);

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<l ; j++ ){
                if(matrix[i][j]=='1')
                    heights[j+1]++;
                else
                    heights[j+1]=0;
            }
            area(heights);
        }


        return maxi ;
    }
};