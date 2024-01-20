class node{
    public:
    node* next,*prev;
    string val;
    node(string s){
        this->val=s;
        this->next=NULL;
        this->prev=NULL;
    }
};
class BrowserHistory {
node *head,*tail,*curr;
public:
    BrowserHistory(string homepage) {
        head=new node(homepage);
        tail=new node("tail");
        head->next=tail;
        tail->prev=head;
        curr=head;
    }
    
    void visit(string url) {
        node* n= new node(url);
        curr->next=n;
        n->prev=curr;
        tail->prev=n;
        n->next=tail;
        curr=curr->next;//visited
    }
    
    string back(int steps) {
        while(steps&&curr!=head){
            curr=curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(steps&&curr->next!=tail){
            curr=curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */