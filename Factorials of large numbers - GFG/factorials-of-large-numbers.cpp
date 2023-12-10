//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
private:
    vector<int>multiply(vector<int>&ans,int x){
       int carry=0;
        for(int i=0;i<ans.size();i++){
            int val=ans[i]*x+carry;
            ans[i]=val%10;
            carry=val/10;
        }
        while(carry){
            ans.push_back(carry%10);
            carry/=10;
        }
        return ans;
    }
public:
    vector<int> factorial(int N){
       vector<int> ans(1, 1);
        for(int i=2;i<=N;i++){
            ans=multiply(ans,i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends