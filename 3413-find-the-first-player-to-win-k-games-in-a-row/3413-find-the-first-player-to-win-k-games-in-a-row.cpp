class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        unordered_map<int,int> hash;

        deque<int> deq ;

        int n = skills.size();

        for(int i = 0; i < n ; i++){
            hash[skills[i]]=0;
            deq.push_back(i);
            // cout<<deq.back()<<endl;
        }

       if (k > n) {
        // Find the iterator pointing to the maximum element
        auto maxElementIt = std::max_element(skills.begin(), skills.end());

        // Calculate the index (distance from the beginning)
        return std::distance(skills.begin(), maxElementIt);
        } 

        while(true){
            int front = deq.front();
            deq.pop_front();
            int back = deq.front();
            deq.pop_front();

            cout<<front<<" "<<back<<endl;

            hash[max(skills[front],skills[back])]++;

            if(skills[front]>skills[back]){
                deq.push_back(back);
                deq.push_front(front);
                if(hash[skills[front]]==k)
                return front;
                }
            else{
                deq.push_back(front);
                deq.push_front(back);
                if(hash[skills[back]]==k)
                    return back;
            }

            // if(hash[skills[front]]==k)
            //     return front;
            // else
            //     return back;
        }

        return 0 ;

    }
};