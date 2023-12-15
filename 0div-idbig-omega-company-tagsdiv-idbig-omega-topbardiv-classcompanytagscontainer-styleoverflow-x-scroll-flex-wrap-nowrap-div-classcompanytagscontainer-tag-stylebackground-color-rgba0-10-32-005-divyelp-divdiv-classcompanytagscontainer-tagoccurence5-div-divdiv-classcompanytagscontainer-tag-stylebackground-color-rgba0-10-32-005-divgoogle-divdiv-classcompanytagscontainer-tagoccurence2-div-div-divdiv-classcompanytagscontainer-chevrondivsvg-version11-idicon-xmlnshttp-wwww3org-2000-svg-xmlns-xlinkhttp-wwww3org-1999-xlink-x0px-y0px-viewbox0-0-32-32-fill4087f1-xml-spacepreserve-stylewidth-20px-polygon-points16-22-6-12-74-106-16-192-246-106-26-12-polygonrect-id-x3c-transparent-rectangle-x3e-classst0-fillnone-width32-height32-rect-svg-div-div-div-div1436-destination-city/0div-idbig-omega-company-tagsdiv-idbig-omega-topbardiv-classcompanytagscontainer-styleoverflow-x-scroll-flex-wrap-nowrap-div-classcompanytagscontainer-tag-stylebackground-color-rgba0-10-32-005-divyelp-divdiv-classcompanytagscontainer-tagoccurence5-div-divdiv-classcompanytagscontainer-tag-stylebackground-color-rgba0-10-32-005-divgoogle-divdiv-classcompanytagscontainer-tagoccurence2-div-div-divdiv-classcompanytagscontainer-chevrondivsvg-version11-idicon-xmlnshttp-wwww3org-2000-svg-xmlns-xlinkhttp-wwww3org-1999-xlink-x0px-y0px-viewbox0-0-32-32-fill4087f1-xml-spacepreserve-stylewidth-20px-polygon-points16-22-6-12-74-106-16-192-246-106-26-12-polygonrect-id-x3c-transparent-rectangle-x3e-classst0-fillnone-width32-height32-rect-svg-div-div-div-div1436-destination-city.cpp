class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string>st;
        unordered_map<string,int>mp;
        for(auto vec:paths){
            string u=vec[0],v=vec[1];
            mp[u]++;
            st.insert(u);st.insert(v);
        }
        for(string s:st){
            if(mp.find(s)==mp.end())return s;
        }
        return "";
    }
};