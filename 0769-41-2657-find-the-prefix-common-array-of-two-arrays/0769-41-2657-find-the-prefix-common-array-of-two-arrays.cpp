class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(),cnt=0;
        vector<int>store(n+1,0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(++store[A[i]]==2)cnt++;
            if(++store[B[i]]==2)cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};