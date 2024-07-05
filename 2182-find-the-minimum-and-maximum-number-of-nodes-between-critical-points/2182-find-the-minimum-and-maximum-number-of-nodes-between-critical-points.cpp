/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int mini=INT_MAX , maxi=-1 ;
        int first = -1 ;
        ListNode* temp = head->next ; 
        int prev = head->val ;
        int count = 1 ;
        int prevcrit = -1 ;

        while(temp->next){
            if(temp->val<prev && temp->val<temp->next->val){
                if(first==-1){
                    first = count; 
                    prevcrit = count ;
                }
                if(first!=count)
                {
                    // if(mini==-1)
                    mini = min(mini,count-prevcrit);
                    maxi = count-first;
                    prevcrit = count ;
                }
            }

            if(temp->val>prev && temp->val>temp->next->val){
                if(first==-1){
                    first = count; 
                    prevcrit = count ;
                }
                else
                {
                    // if(mini==-1)
                    //     mini = count-first;
                    mini = min(mini,count-prevcrit);
                    maxi = count-first;
                    prevcrit = count;

                }
            }
            
            // cout<<prev<<temp->val<< temp->next->val<<endl;
            // cout<<maxi<<"m n"<<mini<<endl;
            // cout<<first<<"f c"<<count<<endl;

            count++;
            prev = temp->val;
            temp = temp->next;
        }

        if(mini!=INT_MAX)
            return { mini , maxi };
        
        return { -1 , -1 };

    }
};