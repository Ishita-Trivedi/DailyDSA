class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>mp;
        vector<int>vec;
        int cost=0;
        for(char ch:word){
            mp[ch]++;
        }
        for(auto x:mp){
            // cout<<x.first<<" "<<x.second<<endl;
            vec.push_back(x.second);
        }
        
        sort(vec.rbegin(),vec.rend());
        for(int i=0;i<vec.size();i++){
            int cnt=vec[i],times=i/8+1;
            
            cost+=times*cnt;
        }
        return cost;
    }
};