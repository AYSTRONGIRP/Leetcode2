class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack <int> st ;
        // int flag = 1 ;
        int n  = asteroids.size();

        for(int i = 0 ; i<n  ; i++){

            if(asteroids[i]>0){
                //positive weight
                st.push(asteroids[i]);
            }else{
                //negative weight
                while(!st.empty() && st.top()>0 && abs(st.top())< abs(asteroids[i]) ){
                    st.pop();
                }

                if(!st.empty()){
                    if(st.top()<0)  
                        st.push(asteroids[i]); 
                    
                    if(st.top() == abs(asteroids[i]))
                    {
                         st.pop();
                    }
                          
                }    
                else{
                    st.push(asteroids[i]);
                }   
            }

        }

        vector<int> ans(st.size()); // Pre-allocate size for efficiency
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans ;
    }
};