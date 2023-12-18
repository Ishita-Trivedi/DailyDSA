//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    bool isValid(int node,vector<int>&colour,bool graph[101][101],int n,int colr){
        for(int k=0;k<n;k++){
            if(k!=node&&graph[k][node]==1&&colour[k]==colr)
            return false;
        }
        return true;
    }
    bool solve(int node,vector<int>&colour,int m,int n,bool graph[101][101]){
        if(node==n)return true;
        for(int colr=1;colr<=m;colr++){
            if(isValid(node,colour,graph,n,colr)){
                colour[node]=colr;
                if(solve(node+1,colour,m,n,graph))return true;
                colour[node]=0;
            }
        }
        return false;
    }
public:
    bool graphColoring(bool graph[101][101], int m, int n) {
      vector<int>colour(n,0);
      return solve(0,colour,m,n,graph);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends