class Solution {
private:
    int n,m,i=0,j=0;
public:
    Solution(int m, int n) {
        this->n=n;this->m=m;
    }
    
    vector<int> flip() {
        int a=i,b=j;
        if(j+1<n)j++;
        else if(i+1<m){
            i++;j=0;
        }
        else
        {i=0;j=0;}
        return {a,b};
    }
    
    void reset() {
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */