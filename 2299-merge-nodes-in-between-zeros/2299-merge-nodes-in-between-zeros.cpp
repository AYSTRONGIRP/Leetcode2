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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* forward = head->next;
        // ListNode* leftBehind = head ;
        ListNode* ans = NULL;
        ListNode* curr = NULL;

        int sum = 0 ;

        while(forward){
            if(forward->val==0){
                ListNode* temp = new ListNode(sum);

                if(!ans)
                    ans = temp;
                else
                    curr->next = temp ;
                
                curr=temp;
                // leftBehind = forward;
                sum = 0 ;
            }
            sum +=forward->val;
            forward = forward->next;
        }

        return ans ; 
    }
};