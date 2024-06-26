class Solution {
public:
    int arrangeCoins(int n) {
        long long l = 1;
        long long r = n ;

        while(l<r)
        {
            long long mid = l+(r-l)/2;

            if(mid*(mid+1)/2>=(long)n)
                r=mid;
            else
                l=mid+1;
        }
        if((l*(l+1))/2==(long)n)
            return l ;
        else
            return l-1;
    }
};