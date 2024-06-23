class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int flag = 0 ;
        int count= 0 ;
        if(ruleKey=="type")
            flag = 0 ;
        if(ruleKey=="color")
            flag = 1 ;
        if(ruleKey=="name")
            flag = 2 ;
        for(auto it:items){
            if(it[flag]==ruleValue)
                count++;
        }

        return count ; 
    }
};