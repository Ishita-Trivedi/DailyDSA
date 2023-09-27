class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==1)return 1;
        map<int,double>mp;//pos,time
        int ans=1;
        for(int i=0;i<position.size();i++)
        mp[position[i]]=(double)(target-position[i])/speed[i];
        auto it=mp.rbegin();
        double prevTime=it->second;
        while(it!=mp.rend()){
            if(it->second>prevTime){
                ans++;
                prevTime=it->second;
                }
                else{
                    prevTime=max(prevTime,it->second);
                }
            ++it;
        }  
        return ans;    
    }
};