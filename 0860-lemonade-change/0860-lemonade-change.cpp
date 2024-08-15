class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int>mp;
        for(int x:bills){
            if(x==5)mp[x]++;
            else if(x==10){
                if(mp[5]==0)return false;
                mp[x]++;
                mp[5]--;
            }
            else if(x==20){
                if(mp[10]>=1&&mp[5]>=1){
                    mp[10]--;
                    mp[5]--;
                }
                else if(mp[5]>=3)
                mp[5]-=3;
                else
                return false;
                mp[x]++;
            }
        }
        return true;
    }
};