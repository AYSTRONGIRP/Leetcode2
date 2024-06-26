class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0 ;
        int row = matrix.size();
        int col = matrix[0].size();
        cout<<col<<"c size r"<<row<<endl;
        int r = matrix.size()*matrix[0].size()-1;
        
        while(l<=r){
           int mid=(r+l)/2;
           cout<<mid<<"div"<<mid/col<<"rem"<<mid%col<<endl;
           cout<<"l"<<l<<"r"<<r<<endl;
           
           if(matrix[mid/col][mid%col]==target){
                return true ;
           } else if(matrix[mid/col][mid%col]>target)
           {
                r=mid-1;
                cout<<"increasing r"<<endl;
           }else{
                l=mid+1;
                cout<<"increasing l"<<endl;
            }
        }
        return false;
    }
};