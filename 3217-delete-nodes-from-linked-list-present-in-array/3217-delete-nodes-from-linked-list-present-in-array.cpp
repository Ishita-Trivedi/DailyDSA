class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(int x : nums) st.insert(x);
        
        while(head && st.find(head->val) != st.end()) {
            ListNode* nxt = head->next;
            head->next = nullptr;  
            head = nxt;
        }
        
        if (!head) return head;
        
        ListNode* curr = head;
        while(curr && curr->next) {
            if(st.find(curr->next->val) != st.end()) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};
