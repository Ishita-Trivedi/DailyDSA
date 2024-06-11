class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(auto x:arr1)
        mp[x]++;
        vector<int>ans;
        for(int x:arr2){
            int cnt=mp[x];
            while(cnt--)
            ans.push_back(x);
            mp[x]=0;
        }
        for(auto x:mp){
            int cnt=x.second;
            while(cnt--)
            ans.push_back(x.first);
        }
        return ans;
    }
};