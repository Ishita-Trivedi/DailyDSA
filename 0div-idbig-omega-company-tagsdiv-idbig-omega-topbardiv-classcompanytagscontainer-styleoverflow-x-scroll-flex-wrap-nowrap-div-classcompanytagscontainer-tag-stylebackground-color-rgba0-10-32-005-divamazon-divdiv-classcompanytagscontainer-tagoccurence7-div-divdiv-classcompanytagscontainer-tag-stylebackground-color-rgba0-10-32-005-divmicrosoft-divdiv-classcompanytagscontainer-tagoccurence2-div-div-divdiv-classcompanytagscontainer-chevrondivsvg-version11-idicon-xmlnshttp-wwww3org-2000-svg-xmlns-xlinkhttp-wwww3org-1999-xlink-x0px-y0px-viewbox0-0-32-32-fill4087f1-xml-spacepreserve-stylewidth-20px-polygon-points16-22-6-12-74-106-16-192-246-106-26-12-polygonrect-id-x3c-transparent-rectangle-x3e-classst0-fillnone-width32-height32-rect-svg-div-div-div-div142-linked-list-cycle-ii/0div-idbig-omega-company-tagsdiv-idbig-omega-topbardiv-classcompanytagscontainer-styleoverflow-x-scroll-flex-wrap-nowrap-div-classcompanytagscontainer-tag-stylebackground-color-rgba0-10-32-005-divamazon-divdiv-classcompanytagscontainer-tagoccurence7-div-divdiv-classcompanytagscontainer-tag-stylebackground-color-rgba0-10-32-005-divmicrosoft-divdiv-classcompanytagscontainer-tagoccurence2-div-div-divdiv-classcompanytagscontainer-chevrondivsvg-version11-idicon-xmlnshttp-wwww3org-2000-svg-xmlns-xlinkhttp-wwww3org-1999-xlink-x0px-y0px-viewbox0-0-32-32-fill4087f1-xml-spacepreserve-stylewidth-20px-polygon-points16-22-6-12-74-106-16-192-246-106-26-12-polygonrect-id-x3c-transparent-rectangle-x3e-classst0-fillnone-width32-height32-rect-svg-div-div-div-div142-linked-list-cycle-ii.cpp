/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return NULL;
        ListNode* slow=head,*fast=head,*start=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow!=start){
                    slow=slow->next;
                    start=start->next;
                }
                return start;
            }
        }
        return NULL;
    }
};