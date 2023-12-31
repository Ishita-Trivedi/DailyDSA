class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char,int>mp;//longest means we maximize
        //so take only the initial for storage
        int maxi=-1;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end())mp[s[i]]=i;
            else{
                maxi=max(i-mp[s[i]]-1,maxi);
            }
        }
        return maxi;
    }
};