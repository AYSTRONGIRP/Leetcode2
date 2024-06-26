class Solution {
public:
    int mySqrt(int x) {
        int l = 0 ;
        int r = x ;
        int count = 1000;

        if(x==1)
            return 1;
        if(x==0)
            return 0 ;

        while(l<r){
            long long mid = l+(r-l)/2;
            // cout<<mid<<"mid"<<endl;
            if(mid*mid>x)
                r=mid;
            else
                l=mid+1;

        }
        return l-1 ;
    }
};