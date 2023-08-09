class Solution {
public:
    bool canMeasureWater(int a, int b, int target) {
        if((a+b)<target||target<0)return false;
        set<int>visited;
        queue<int>q;
        //inital state is zero
        q.push(0);visited.insert(0);
        int states[]={-a,a,-b,-b};
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int val=curr+states[i];
                if(val==target)return true;
                if(val>(a+b)||val<0)continue;
                if(visited.find(val)==visited.end()){
                    q.push(val);
                    visited.insert(val);
                }
            }
        }
        return false;
    }
};