class Solution {
public:
    int passThePillow(int n, int time) {
        int div = time/(n-1);
        int rem = time%(n-1);

        if(div&1)//odd
            return n-rem;
        
        return rem+1 ;

    }
};