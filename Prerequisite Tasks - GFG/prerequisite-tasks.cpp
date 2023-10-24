//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    int indeg[N]={0};
	    vector<int>adj[N];
	    for(auto x:prerequisites){
	        int o=x.first,t=x.second;
	        indeg[t]++;
	        adj[o].push_back(t);
	    }
	    vector<int>topo;queue<int>q;
	    for(int i=0;i<N;i++){
	        if(indeg[i]==0)q.push(i);
	    }
	    while(!q.empty()){
	        int n=q.front();q.pop();
	        topo.push_back(n);
	        for(int x:adj[n]){
	            if(--indeg[x]==0)
	            q.push(x);
	        }
	    }
	    return topo.size()==N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends