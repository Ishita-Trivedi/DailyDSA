class Solution {
    typedef long long ll;
public:
    ll sumOD(ll n){
        if(n<=0)return 0;
        return n%10+sumOD(n/10);
    }
    int getLucky(string s, int k) {
        ll sum=0;
        for(char ch:s){
            ll val=ch-'a';
            val++;
            sum+=sumOD(val);
        }
        k--;
        while(k--){
            sum=sumOD(sum);
        }
        return sum;
    }
};