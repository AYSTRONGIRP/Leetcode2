class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0 ; 
        int r = n-1 ;

        while(l<r){
            long mid = l+(r-l)/2;
            if(letters[mid]>target)
                r=mid;
            else
                l=mid+1;
        }
        if(letters[n-1]>target)
            return letters[l];
        else
            return letters[0];
    }
};