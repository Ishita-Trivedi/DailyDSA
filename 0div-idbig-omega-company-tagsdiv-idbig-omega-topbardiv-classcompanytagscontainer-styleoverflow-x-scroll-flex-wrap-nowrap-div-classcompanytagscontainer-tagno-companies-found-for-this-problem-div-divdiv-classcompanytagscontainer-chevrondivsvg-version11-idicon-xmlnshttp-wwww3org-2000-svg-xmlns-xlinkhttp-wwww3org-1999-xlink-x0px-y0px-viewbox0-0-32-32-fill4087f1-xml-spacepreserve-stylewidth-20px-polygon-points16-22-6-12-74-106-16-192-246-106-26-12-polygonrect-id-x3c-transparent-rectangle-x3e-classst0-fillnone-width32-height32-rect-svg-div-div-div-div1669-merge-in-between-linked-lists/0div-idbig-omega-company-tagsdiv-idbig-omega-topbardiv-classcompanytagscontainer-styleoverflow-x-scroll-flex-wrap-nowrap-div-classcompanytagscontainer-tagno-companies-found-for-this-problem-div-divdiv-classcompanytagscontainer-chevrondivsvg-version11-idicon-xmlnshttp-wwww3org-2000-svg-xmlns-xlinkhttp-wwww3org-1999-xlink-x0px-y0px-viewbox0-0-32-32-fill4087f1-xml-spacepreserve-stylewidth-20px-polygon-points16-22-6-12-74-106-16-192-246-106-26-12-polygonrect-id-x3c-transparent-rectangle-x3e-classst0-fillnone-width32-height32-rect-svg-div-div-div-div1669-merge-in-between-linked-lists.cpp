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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr=list1,*ap,*bp,*tail2=list2;
        while(tail2->next){
            tail2=tail2->next;
        }
        for(int i=0;i<=b+1;i++){
            if(i==a-1)
            ap=curr;
            bp=curr;
            curr=curr->next;
        }
        ap->next=list2;
        tail2->next=bp;
        return list1;
    }
};