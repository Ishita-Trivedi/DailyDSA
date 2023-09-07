//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int kLevelSum(int K, string S) {
       int level=-1,sum=0;
       string num="";
       for(int i=0;i<S.length();i++){
           if(S[i]=='('){
               if(num!=""&&level==K){
                   sum+=stoi(num);
               }
               num="";//reset at every level
               //we increment AFTER so at level 2 we store value of level 1
               level++;continue;
           }
           else if(S[i]==')'){
               level--;continue;
           }
           num+=S[i];
       }
       return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>K;
        cin>>S;

        Solution ob;
        cout << ob.kLevelSum(K,S) << endl;
    }
    return 0;
}
// } Driver Code Ends