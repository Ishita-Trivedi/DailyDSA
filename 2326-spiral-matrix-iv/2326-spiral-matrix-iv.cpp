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
    vector<vector<int>> spiralMatrix(int rows, int cols, ListNode* head) {
    vector<vector<int>>matrix(rows,vector<int>(cols,-1));
    if(!head)return matrix;
    ListNode* curr=head;
    int rs=0,re=rows-1,cs=0,ce=cols-1;
    while(rs<=re&&cs<=ce&&curr){
        for(int c=cs;c<=ce;c++){
            if(!curr)break;
            matrix[rs][c]=curr->val;
            curr=curr->next;
        }
        rs++;
        if(rs<=re&&cs<=ce&&curr){
        for(int r=rs;r<=re;r++){
            if(!curr)break;
            matrix[r][ce]=curr->val;
            curr=curr->next;
        }
        }
        ce--;
        //<-
        if(rs<=re&&cs<=ce&&curr){
        for(int c=ce;c>cs;c--){
            if(!curr)break;
            matrix[re][c]=curr->val;
            curr=curr->next;
        }
        }
        if(rs<=re&&cs<=ce&&curr){
        for(int r=re;r>=rs;r--){
            if(!curr)break;
            matrix[r][cs]=curr->val;
            curr=curr->next;
        }
        }
        cs++;re--;
    }
    return matrix;
    }
};