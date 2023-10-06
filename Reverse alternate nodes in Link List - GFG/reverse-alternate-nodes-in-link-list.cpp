//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse(struct Node *head){
        if(!head||!head->next)return head;
        else{
            struct Node* ptr=reverse(head->next);
            (head->next)->next=head;
            head->next=NULL;
            return ptr;
        }
    }
    void rearrange(struct Node *odd)
    {
        if(!odd||!odd->next)return ;
        struct Node* head=odd;
        struct Node* head2=odd->next;
        struct Node* c=odd;
        struct Node* c2=odd->next;
        while(c2){
            c->next=c2->next;
            if(c->next)c=c->next;
            if(c2->next)
            c2->next=c2->next->next;
            c2=c2->next;
        }
        c->next=reverse(head2);
        odd=head;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends