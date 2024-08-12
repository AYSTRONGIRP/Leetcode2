class KthLargest {
public:
        priority_queue<int,vector<int>,greater<int>>pq;
        int size;
    KthLargest(int k, vector<int>& nums) 
    {
        size=k;
        for(auto l:nums)
        {
            cout<<l<<endl;
            pq.push(l);
        }
    }
    
    int add(int val) 
    {
        pq.push(val);
        while(pq.size()>size)
        {
            pq.pop();
        }    
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */