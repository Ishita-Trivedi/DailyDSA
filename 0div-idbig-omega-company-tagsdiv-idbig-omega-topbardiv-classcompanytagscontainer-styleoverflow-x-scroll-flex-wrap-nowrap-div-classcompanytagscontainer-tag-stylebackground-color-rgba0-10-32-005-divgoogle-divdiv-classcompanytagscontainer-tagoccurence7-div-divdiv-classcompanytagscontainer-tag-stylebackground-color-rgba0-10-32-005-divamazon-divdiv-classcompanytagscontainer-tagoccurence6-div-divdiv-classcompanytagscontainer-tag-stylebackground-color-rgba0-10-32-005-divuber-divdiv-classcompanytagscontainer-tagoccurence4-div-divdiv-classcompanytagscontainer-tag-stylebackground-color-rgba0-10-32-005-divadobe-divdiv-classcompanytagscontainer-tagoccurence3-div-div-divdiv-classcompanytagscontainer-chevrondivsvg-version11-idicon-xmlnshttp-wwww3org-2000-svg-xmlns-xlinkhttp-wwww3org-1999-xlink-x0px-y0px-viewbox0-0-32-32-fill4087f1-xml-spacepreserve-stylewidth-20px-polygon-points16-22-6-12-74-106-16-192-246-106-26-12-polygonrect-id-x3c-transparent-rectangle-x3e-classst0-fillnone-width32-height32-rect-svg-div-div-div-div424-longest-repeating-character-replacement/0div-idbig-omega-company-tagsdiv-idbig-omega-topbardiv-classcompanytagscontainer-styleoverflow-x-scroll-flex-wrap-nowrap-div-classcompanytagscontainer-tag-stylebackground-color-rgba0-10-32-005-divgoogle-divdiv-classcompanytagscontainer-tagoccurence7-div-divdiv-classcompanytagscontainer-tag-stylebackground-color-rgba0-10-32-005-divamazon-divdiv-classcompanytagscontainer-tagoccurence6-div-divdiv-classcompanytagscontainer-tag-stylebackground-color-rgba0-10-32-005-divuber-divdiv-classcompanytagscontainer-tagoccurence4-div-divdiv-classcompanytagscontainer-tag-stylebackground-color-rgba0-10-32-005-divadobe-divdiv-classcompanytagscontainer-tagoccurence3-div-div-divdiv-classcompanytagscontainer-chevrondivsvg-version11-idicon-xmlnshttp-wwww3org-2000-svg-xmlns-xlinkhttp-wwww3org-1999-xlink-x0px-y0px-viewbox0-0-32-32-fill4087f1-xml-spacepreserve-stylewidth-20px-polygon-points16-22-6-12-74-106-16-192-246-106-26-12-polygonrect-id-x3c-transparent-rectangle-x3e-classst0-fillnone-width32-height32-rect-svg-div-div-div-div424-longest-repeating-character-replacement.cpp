class Solution {
public:
    char most(unordered_map<char,int>&mp){
        int maxi=0;char ch;
        for(auto x:mp){
            if(x.second>maxi){
                maxi=x.second;
                ch=x.first;
            }
        }
        return ch;
    }
    int characterReplacement(string s, int k) {
        int ws=0,we=0,maxi=0;
        unordered_map<char,int>mp;
        while(we<s.length()){
            mp[s[we]]++;char ch=most(mp);
             while(((we-ws+1)-mp[ch])>k){
                 cout<<ch<<ws<<endl;
                 mp[s[ws]]--;ws++;
                  ch=most(mp);
             }
            maxi=max(maxi,we-ws+1);
            we++;
        }
        return maxi;
    }
};
