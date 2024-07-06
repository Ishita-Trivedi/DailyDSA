class Solution {
public:
    int passThePillow(int n, int time) {
        if(time<n)
        return time+1;
        int t=1,opr=1;
        while(time--){
            t+=opr;
            if(t==n||t==1)
            opr*=(-1);

        }
        return t;
    }
};