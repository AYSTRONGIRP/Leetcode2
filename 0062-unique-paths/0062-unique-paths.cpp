class Solution {
public:

    int NCX (int n , int x){
        long long res = 1 ;

        if(x==0 || n==x)
        return 1 ;

        // res = n ; 
        cout<<n<<x<<endl;

        // cout<<res<<endl;
        for(int i = 1 ; i <= x ; i++){
            res = res*(n-(i)+1);
            res = res/i;

            cout<<res<<endl;
        }
        cout<<res;
        return res ;
    }

    int uniquePaths(int m, int n) {
        if(n<m)
        return NCX((m+n-2),n-1);
        else
        return NCX((m+n-2),m-1);
    }
};