class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v ; 
        for(int i = 1 ; i <= n ; i++ ){
            v.push_back(i);
        }
        int pos = k-1 ;

        while(v.size()!=1){
            // cout<<pos<<'p'<<endl;
            // cout<<v[pos]<<endl;
            v.erase(v.begin()+pos);
            // pos = pos;
            // for(auto it : v){
            //     cout<<it<<' ';
            // }
            // cout<<endl;
            // if(pos==v.size()){
                if(pos!=0)
                    pos= pos-1;
                else
                    pos=v.size()-1;
            // }
            // else{

            // }
            if(v.size()==1)
                break ; 
            // if(pos+k>(v.size()))
            pos = (pos+k)%(v.size());
            // else
            //     pos=pos+k;
        }

        return v[0];
    }
};