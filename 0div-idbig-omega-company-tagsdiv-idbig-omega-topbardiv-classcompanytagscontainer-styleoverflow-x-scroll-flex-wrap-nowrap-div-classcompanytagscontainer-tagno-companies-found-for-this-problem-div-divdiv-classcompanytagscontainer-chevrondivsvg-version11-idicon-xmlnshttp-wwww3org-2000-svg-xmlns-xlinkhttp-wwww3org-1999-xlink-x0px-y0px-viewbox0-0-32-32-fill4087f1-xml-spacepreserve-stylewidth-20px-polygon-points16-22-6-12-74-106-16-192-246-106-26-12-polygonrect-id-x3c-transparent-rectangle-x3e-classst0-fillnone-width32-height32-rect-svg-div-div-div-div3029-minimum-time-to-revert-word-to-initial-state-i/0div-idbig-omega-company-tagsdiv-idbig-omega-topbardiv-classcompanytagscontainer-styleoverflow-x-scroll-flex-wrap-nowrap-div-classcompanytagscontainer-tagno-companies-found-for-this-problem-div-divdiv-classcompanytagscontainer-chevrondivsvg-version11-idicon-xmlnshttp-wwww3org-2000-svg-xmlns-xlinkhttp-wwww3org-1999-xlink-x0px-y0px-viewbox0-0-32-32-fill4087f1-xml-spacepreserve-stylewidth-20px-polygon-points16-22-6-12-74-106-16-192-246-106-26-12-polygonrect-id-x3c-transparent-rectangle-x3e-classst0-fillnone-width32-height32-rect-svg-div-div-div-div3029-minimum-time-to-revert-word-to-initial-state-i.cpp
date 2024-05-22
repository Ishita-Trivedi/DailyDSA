class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.length(),c=1;
        for(int i=k-1;i<n;i+=k){
            bool check=true;
            int l=0;
            for(int j=i+1;j<n;j++){
                if(word[l]!=word[j]){
                    check=false;
                    break;
                }
                l++;
            }
            if(check)return c;
            c++;
        }
        return c;
    }
};