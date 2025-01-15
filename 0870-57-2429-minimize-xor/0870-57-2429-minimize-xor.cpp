class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        vector<int>val(32,0);
        for(int i=0;i<32;i++){
            if(num2&(1<<i))
            cnt++;
        }
        for(int i=31;i>=0;i--){
            if((num1&(1<<i))&&cnt){
                val[i]=1;
                cnt--;
            }
        }
        for(int i=0;i<32;i++){
            if(val[i]==0&&cnt){
                cnt--;
                val[i]=1;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(val[i])
            ans+=(1<<i);

        }
        return ans;
    }
};