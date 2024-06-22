class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi=0;
        for(int i=0;i<sentences.size();i++){
            int count=0;
            for(int j=0;j<sentences[i].length();j++){
                if(sentences[i][j]==' '){count++;
                maxi=max(count,maxi);}
            }
        }
        return maxi+1;  
    }
};