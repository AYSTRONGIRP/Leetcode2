class Solution {
public:
    void reverseS(string &s, int l , int r){
        // int n = s.size();
        // for(int i = l ; i < r/2  ;i++){
        //     s[i]=s[n-i-1];
        // }
        reverse(s.begin()+l,s.begin()+r);
    }
    string reverseParentheses(string s) {
        stack <int> st ;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(s[i]=='('){
                st.push(i);
                continue;
            }
            if(s[i]==')'){
                int top = st.top();
                st.pop();
                reverseS(s,top,i);
                continue;
            }
        }
        string res="";
        for(char it :s){
            if(it==')' || it=='(')
                continue;
            res+=it;
        }
        return res;
    }
};