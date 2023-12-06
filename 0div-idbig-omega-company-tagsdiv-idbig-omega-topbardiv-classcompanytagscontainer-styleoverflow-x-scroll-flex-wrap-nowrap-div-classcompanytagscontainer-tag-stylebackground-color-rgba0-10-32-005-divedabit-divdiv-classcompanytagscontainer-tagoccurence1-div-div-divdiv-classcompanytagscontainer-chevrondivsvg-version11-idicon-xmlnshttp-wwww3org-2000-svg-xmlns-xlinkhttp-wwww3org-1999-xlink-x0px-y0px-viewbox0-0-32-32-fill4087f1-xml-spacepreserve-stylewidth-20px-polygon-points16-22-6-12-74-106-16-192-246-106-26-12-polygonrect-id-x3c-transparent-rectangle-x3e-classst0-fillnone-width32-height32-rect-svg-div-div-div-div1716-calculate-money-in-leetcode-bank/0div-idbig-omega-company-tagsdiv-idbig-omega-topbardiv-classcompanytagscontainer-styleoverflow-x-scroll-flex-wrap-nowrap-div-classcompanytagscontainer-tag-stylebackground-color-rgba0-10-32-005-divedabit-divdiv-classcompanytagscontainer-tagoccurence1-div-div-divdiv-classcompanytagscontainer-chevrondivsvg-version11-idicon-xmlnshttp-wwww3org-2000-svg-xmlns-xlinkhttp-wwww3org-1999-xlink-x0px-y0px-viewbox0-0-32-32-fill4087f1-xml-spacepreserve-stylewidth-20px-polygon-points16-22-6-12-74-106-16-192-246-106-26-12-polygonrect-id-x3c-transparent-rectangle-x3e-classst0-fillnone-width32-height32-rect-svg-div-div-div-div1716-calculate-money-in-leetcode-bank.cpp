class Solution {
public:
    int totalMoney(int n) {
        int start=0,sum=0,curr=0;
        for(int i=1;i<=n;i++){
            if(i%7==1){curr=start+1;start++;}
            else
            curr++;
            sum+=curr;
        }
        return sum;
    }
};