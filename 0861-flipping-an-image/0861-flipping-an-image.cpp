class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto& it: image){
            int n = it.size();
            reverse(it.begin(),it.end());
            for(int i = 0 ; i< n ; i++){
                it[i]^=1;
            }
        }
        return image;
    }
};