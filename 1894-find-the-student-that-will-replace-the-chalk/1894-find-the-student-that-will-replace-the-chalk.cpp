class Solution {
typedef long long ll;
public:
    int chalkReplacer(vector<int>& chalk, int k) {
      int n=chalk.size(),start=0;
      vector<ll>prefix(n,0);prefix[0]=chalk[0];
      for(int i=1;i<n;i++)
        prefix[i]=prefix[i-1]+chalk[i];
      int lb=lower_bound(prefix.begin(),prefix.end(),k)-prefix.begin();
     if(lb==n){
        k%=prefix[n-1];
        start=0;
     }
     else{
        if(prefix[lb]>k)return lb;
        k-=prefix[lb];
        start=(lb+1)%n;
     }
     while(1){
        if(chalk[start]>k)return start;
        k-=chalk[start];
        start=(start+1)%n;
     }
     return -1;
    }
};