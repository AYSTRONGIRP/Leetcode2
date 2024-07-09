class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        double res = 0; 
        long long time = customers[0][0] ;
        long long wTime = 0 ;
        // cout<<time <<endl;
        for(int i = 0 ; i < n ; i++){
            int &start = customers[i][0];
            int & end = customers[i][1];
            // cout<<"----"<<endl;
            // cout<<start<<endl;
            // cout<<end<<endl;

            if(time > start){
                //waiting 
                wTime += time - start ; 
                // cout<<"waiting "<<wTime<<endl;
                time +=end;
            }else{
               //no waiting
               time=start+end;  
            }
            wTime +=end ; 
            // cout<<time<<endl;
            // cout<<"waiting time"<<wTime<<endl;
            
            // cout<<start<<endl;
            // cout<<end<<endl;
        }
        // cout<<wTime<<endl;
        res = (double)wTime / (double)n ;
        return res ;
    }
};