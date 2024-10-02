class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>vec(arr.begin(),arr.end());
        vector<int>ans;
        sort(vec.begin(),vec.end());
        map<int,int>mp;
        int start=1,n=arr.size();
        for(int x:vec){
           if(mp.find(x)==mp.end()){
            mp[x]=start;
            start++;
           }
        }
        for(int x:arr)
        ans.push_back(mp[x]);
        return ans;
    }
};