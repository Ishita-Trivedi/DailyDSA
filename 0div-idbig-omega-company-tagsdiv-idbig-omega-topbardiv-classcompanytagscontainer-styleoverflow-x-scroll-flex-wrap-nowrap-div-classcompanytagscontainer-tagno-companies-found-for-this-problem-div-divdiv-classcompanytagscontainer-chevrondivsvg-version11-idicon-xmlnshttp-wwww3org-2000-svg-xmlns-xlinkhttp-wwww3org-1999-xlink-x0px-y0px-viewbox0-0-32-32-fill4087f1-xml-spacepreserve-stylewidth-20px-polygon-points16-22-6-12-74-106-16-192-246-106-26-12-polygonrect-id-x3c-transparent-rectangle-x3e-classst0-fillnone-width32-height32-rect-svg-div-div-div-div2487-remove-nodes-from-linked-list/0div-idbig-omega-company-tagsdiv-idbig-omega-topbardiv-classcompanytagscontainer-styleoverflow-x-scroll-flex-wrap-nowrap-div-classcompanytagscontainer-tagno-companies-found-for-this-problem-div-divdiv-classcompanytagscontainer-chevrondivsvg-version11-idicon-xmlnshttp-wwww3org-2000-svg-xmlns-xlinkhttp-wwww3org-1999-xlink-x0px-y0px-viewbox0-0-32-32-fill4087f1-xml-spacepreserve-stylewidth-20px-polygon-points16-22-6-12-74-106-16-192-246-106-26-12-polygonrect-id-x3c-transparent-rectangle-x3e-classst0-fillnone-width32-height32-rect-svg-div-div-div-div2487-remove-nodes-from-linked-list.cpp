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
    ListNode* reverse(ListNode* head)
    {
        if(head==NULL||head->next==NULL)
        return head;
        else
        {
            ListNode* ptr=reverse(head->next);
            (head->next)->next=head;
            head->next=NULL;
            return ptr;
        }
    }
    ListNode* removeNodes(ListNode* head) {
       if(head==NULL||head->next==NULL)
        return head;
        ListNode* newll =reverse(head);
        ListNode* curr=newll;
        // int maxi=curr->val;
         ListNode* prev=newll;
        //  curr=curr->next;
       
        while(curr)
        {
            if(curr->val >= prev->val)
            {
                prev=curr;
                curr=curr->next;
            }
            else
{
    prev->next=curr->next;curr=curr->next;
}
        }
        
        head=reverse(newll);
        return head;

    }
};