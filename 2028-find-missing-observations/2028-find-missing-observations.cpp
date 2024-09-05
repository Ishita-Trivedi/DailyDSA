class Solution {
public:
    vector<int>ans;
    // bool found=false;
    // void helper(int sum,int n,vector<int>&nrolls){
    //     if(found||sum<0||n<0)return;
    //     if(n==0&&sum==0){
    //         ans=nrolls;
    //         found=true;
    //         return;
    //     }
    //     for(int i=1;i<=6;i++){
    //         if(sum>=6){
    //             nrolls.push_back(i);
    //              helper(sum-i,n-1,nrolls);
    //              nrolls.pop_back();
    //         }           
    //     }
    // }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int msum=accumulate(rolls.begin(),rolls.end(),0),m=rolls.size(),i=0,nsum;
        nsum=(mean*(m+n))-msum;
        // cout<<nsum<<endl;
        if(nsum>(6*n))return {};
        vector<int>nrolls(n,0);
        while(nsum>=6&&i<n){
            nrolls[i]=6;
            nsum-=6;
            i++;
        }
        cout<<nsum<<endl;
        if(nsum>0){
            if(nsum>6||i>=n)return {};
            nrolls[i]=nsum;
            i++;
            nsum=0;
        }
        int j=0;
        while(i<n){
            while(j<n&&nrolls[j]<=1)j++;
            if(j>=n)return{};
            nrolls[i]=1;
            i++;
            nrolls[j]--;
        }
        return nrolls;
    }
};