class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int coins[3]={0};
        int n = bills.size();
        for(int i =0 ; i< n ; i++){
            if(bills[i]==5){
                coins[0]++;
            }else if( bills[i]==10){
                if(coins[0]==0)
                    return false;
                
                coins[0]--;
                coins[1]++;
            }else{

                if((coins[1]==0 && coins[0]<=2) || (coins[1]>0 && coins[0]==0)){
                    return false;
                }
                if(coins[1]>=1){
                    coins[0]--;
                    coins[1]--;
                    continue;
                }else{
                   coins[0]-=3;    
                }
            }
        }
        return true;
    }
};