class Solution {
public:
    void eraseRange(int l,int r,set<int>&st){
        auto lb=st.lower_bound(l);
        auto ub=st.upper_bound(r);
        st.erase(lb,ub);
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        set<int>st;
        for(int i=0;i<n;i++)
        st.insert(i);
        for(auto vec:queries){
            int u=vec[0],v=vec[1];
            eraseRange(u+1,v-1,st);
            ans.push_back(st.size()-1);
        }
        return ans;
    }
};