class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(string s:words){
            string rev=s;
            reverse(rev.begin(),rev.end());
            if(s==rev)return s;
        }
        return "";
    }
};