#define LL long long
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod=1e9+7;
        for(LL i=n-1;i>=0;i--){
            LL val=(LL)(1)<<i;//<< itself does 2's power i shift
            if((a&val)==(b&val))//both already same
            {
                //either both zero/one
                //as we need to increase the value of smaller
                //so both set
                a=a|val;b=b|val;
            }
            else{
                if(a>b)swap(a,b);
                //now always b is greater, a is smaller
                //greater's value decrease=reset
                //smaller's value increase=set
                b=b&(~val);//reset
                a=a|val;//set
            }
        }
        return (int)(((a%mod)*(b%mod))%mod);
    }
};