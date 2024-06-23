class Solution {
public:
    int maxArea(vector<int>& height) {

        // vector <int > prefix(1e4+1 , 0 );
        int ans = 0 ;
        int n = height.size();

        // for(int i = 0;i< n ; i++){
        //     prefix[height[i]]=i;
        // }

        // int maxi = 0 ; 
        // for(int i = 1e4 ; i>= 0 ; i--){
        //     prefix[i]=max(maxi,prefix[i]);
        //     maxi = prefix[i];
        // }

        // // for(auto it : prefix){
        // //     cout<<it<<' ';
        // // }
        

        // for(int i = 0 ; i<n ;i++){
        //     ans=max(ans,height[i]*(prefix[height[i]]-i));
        // }
        int i = 0 , j = n-1 , width;
        while(i<j){
            width = j-i;
            ans = max(ans,  width * (min(height[i],height[j]) ) );

            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }

        }

        return ans ;
    }
};