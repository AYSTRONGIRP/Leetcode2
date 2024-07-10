class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(string s :logs){
            if(s=="../"){
                if(count>0)
                    count--;
            }else if (s=="./"){

            }else{
                count++;
            }
        }
        return count ; 
    }
};