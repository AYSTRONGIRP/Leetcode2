class CustomStack {
public:
    stack<pair<int,int>> st;
    stack<pair<int,int>> st2;
    int size;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        // if(st.empty)
        if(st.size()<size)
            st.push({x,0});
    }
    
    int pop() {
        if(st.empty())
            return -1;
        pair<int, int> temp = st.top();
        st.pop();
        if(!st.empty())
            st.top().second = temp.second+st.top().second;
        return temp.first+temp.second ;
    }
    
    void increment(int k, int val) {
        while(st.size()>k){
            st2.push(st.top());
            st.pop();
        }
        if(st.empty())
        {
           cout<<"empty ";
           return ;
        }
        st.top().second+=val;
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */