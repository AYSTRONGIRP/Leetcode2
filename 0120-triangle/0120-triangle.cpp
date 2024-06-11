class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int l = triangle.size();
        int n = triangle[0].size();

        for(int i = 1 ; i < l ; i++){

            triangle[i][0]+=triangle[i-1][0];

            for(int j = 1 ; j < triangle[i].size();j++)
            {
                if(j!=triangle[i].size()-1)
                triangle[i][j]+=min(triangle[i-1][j],triangle[i-1][j-1]);
                else
                triangle[i][j]+=triangle[i-1][j-1];
            }
        }

        for(auto it :triangle){
            for(auto it2 :it){
                cout<<it2<<' ';
            }
            cout<<endl;
        }

        return *min_element(triangle[l-1].begin(),triangle[l-1].end());
    }
};