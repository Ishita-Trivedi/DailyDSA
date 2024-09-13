class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        vector<int>prefix(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++)
        prefix[i]^=prefix[i-1];
        for(auto vec:queries){
            int l=vec[0],r=vec[1];
            int val=prefix[r];
            if(l>=1)
            val^=prefix[l-1];
            ans.push_back(val);
        }
        return ans;
    }
};