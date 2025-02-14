typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        int count=0;
        for(int x:nums){
            pq.push(x);
        }
        while(pq.size()>1&&pq.top()<k){
            ll a=pq.top();pq.pop();
            ll b=pq.top();pq.pop();
            ll val=2*a+b;
            pq.push(val);
            count++;
        }
        return count;
    }
};