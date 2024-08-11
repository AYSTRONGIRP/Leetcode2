class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0 ; 

        for(auto it : commands){
            if(it=="UP")
                ans-=n;
            if(it=="RIGHT")
                ans+=1;
            if(it=="DOWN")
                ans+=n;
            if(it=="LEFT")
                ans-=1;
        }
        return ans ; 
    }
};