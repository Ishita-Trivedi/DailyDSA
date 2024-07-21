class Solution {
public:
typedef long long ll;
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        ll opr=0,pbar=0,nbar=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ll diff=target[i]-nums[i];
            if(diff==0)
                pbar=nbar=0;
            else if (diff>0){
                if(diff>pbar)
                    opr+=(diff-pbar);
                pbar=diff;
                nbar=0;
            }
            else{
                pbar=0;
                if(-diff>nbar)
                opr+=(-diff-nbar);
                nbar=-diff;
            }
        }
        return opr;
    }
};