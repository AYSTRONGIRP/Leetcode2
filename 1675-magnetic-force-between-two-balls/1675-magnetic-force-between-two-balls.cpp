class Solution {
public:
    bool isValid(int dis , vector<int> &stalls , int k ){
        int n = stalls.size();
        int i = 0 , j = 1 ;
        int count = 1;

        // cout<<"entered"<<endl;
        // cout<<dis<<endl;
        while(j<n){
            if(stalls[j]-stalls[i]>=dis){
                i=j;
                // j++;
                count++;
            }
            if(count==k){
                    // cout<<"success"<<dis<<endl;
                    // cout
                    return true;}
            j++;
        }
        // cout<<"exited"<<count<<endl;
        
        return count>=k ;
    }
    int maxDistance(vector<int>& stalls, int m) {
        int i = 0 ;
        int j = 1e9;
        int n = stalls.size();
        int ans = stalls[n-1]-stalls[0];
        sort(stalls.begin(),stalls.end());
        
        if(n<m)
            return -1;
        
        while(i<=j){
            int mid = i +(j-i)/2 ;
            if(isValid(mid,stalls,m)){
                ans = mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        
        return ans ;
    }
};