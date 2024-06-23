class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string w1 , w2 ;
        for(auto it :word1){
            w1+=it;
        }
        for(auto it :word2){
            w2+=it;
        }

        // cout<<w1 <<endl;
        // cout<<w2 <<endl;

        if(w1.compare(w2))
            return false ;
        
        return true ;
    }
};