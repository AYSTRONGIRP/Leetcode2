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
    ListNode* middleNode(ListNode* head) {
        ListNode *fast ,*slow ;
        fast = slow = head ;

        while(fast){
            if(fast && !fast->next)
                return slow;
            
            fast = fast->next->next;
            slow= slow->next;
        }

        return slow;
    }
};