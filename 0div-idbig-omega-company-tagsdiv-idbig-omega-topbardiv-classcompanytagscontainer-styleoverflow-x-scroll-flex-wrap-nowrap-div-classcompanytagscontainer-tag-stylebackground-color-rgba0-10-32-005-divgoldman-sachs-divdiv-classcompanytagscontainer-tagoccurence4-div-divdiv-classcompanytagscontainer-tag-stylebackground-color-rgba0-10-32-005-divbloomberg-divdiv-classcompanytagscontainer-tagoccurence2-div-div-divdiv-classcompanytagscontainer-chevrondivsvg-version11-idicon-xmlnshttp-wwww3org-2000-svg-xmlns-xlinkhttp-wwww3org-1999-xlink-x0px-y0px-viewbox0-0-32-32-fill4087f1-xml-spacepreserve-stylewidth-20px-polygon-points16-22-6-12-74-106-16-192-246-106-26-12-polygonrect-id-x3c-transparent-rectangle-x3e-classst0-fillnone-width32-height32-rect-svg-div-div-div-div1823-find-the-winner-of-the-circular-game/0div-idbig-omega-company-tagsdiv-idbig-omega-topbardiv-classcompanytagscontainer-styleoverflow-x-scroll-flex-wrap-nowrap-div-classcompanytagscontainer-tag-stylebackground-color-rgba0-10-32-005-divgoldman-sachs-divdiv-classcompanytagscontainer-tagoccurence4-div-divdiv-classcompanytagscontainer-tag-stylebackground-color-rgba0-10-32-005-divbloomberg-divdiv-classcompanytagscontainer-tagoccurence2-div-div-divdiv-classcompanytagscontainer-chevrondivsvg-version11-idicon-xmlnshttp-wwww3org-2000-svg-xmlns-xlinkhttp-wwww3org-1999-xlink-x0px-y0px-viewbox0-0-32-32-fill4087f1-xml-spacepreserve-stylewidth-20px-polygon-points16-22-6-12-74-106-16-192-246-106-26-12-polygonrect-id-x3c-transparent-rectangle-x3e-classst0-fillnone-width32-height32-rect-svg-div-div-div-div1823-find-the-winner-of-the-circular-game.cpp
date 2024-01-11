class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>frnds(n);
        for(int i=0;i<n;i++)
        frnds[i]=i+1;
        int start=0,c=0;
        while(true){
            if(frnds.size()==1)break;
            int a=(start+k-1)%n;start=a;
            frnds.erase(frnds.begin()+a);//del
            n--;
            start%=n;
        }
        return frnds[0];
    }
};