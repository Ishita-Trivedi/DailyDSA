class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        unordered_map<char,int>freq;
        vector<int>wordSizes;
        int even=0,odd=0,ans=0;
        for(string w:words){
            for(char ch:w)
            freq[ch]++;
            wordSizes.push_back(w.length());
        }
        sort(wordSizes.begin(),wordSizes.end());
        for(auto x:freq)
        even+=x.second/2,odd+=x.second%2;
        for(int len:wordSizes){
            if(len%2==1){
                if(odd)odd--;
                else{
                    even--;
                    odd++;
                }
            }
            //not enough to form the palindromes any more
            if(even<len/2)break;
            even-=len/2;
            ans++;
        }
        return ans;
    }
};