class Solution {
public:
    int minChanges(int n, int k) {
        int res = 0 ;

        for(int i = 0 ; i < 32 ; i++){
            if( ((n >> i )&1) != ((k>>i)&1) ){
                if( ((k>>i)&1))
                    return -1;
                
                res++;
            }
        }

        return res ; 
    }
};