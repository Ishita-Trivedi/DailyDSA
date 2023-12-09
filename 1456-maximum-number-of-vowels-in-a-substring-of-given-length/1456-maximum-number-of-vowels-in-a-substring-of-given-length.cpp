class Solution {
public:
    int maxVowels(string s, int k) {
        int ws=0,maxCount=0,count=0;
        for(int we=0;we<s.length();we++){
            if(s[we]=='a'||s[we]=='e'||s[we]=='i'||s[we]=='o'||s[we]=='u')
            count++;
            while(ws<we&&(we-ws+1)>k){
       if(s[ws]=='a'||s[ws]=='e'||s[ws]=='i'||s[ws]=='o'||s[ws]=='u')
            count--;
            ws++;         
            }
            maxCount=max(maxCount,count);
        }
        return maxCount;
    }
};