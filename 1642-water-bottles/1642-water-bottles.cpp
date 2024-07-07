class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0 ;
        int rem = 0 ;
        int newb = 0 ;
        while(numBottles){
            ans +=numBottles;
            newb = (numBottles+rem)/numExchange ;
            rem =  (numBottles+rem)%numExchange;
            numBottles = newb;
        }
        return ans;
    }
};