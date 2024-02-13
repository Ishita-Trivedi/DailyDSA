class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int i=0,j=mp[s[0]],prev=-1;
        while(i<n){
            if(mp[s[i]]>j)
            j=mp[s[i]];
            if(i==j)
            {
                cout<<j<<endl;
                if(prev==-1)
                ans.push_back(j+1);
                else
                ans.push_back(j-prev);
                prev=j;
            }
            i++;
        }
        return ans;
    }
};