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
private:
    // ListNode* reverse(ListNode* head){
    //     if(!head||!head->next)return head;
    //     else{
    //         ListNode* ptr=reverse(head->next);
    //         head->next->next=head;
    //         head->next=NULL;
    //         return ptr;
    //     }
    // }
    ListNode* reverse(ListNode* head){
        //iterative reverse this time
        ListNode* newHead=NULL;
        while(head){
            ListNode* nex=head->next;
            head->next=newHead;
            newHead=head;
            head=nex;
        }
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode* s=head,*fast=head;
        while(fast->next&&fast->next->next){
            s=s->next;
            fast=fast->next->next;
        }
        ListNode* d=head;
        s->next=reverse(s->next);
        //one step ahead 
        s=s->next;
        while(s){
            // cout<<d->val<<" "<<s->val<<endl;
            if(d->val!=s->val)return false;
            d=d->next;s=s->next;
        }
        return true;
    }
};