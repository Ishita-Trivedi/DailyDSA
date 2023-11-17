//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
public:
    vector<int>rank,parent,size;
    DisjointSet(int n){//defining the constructor for initialization
        rank.resize(n+1,0);//secure for 1 based index too
        parent.resize(n+1);
        size.resize(n + 1,1);
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    int findParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findParent(parent[node]);//path compression->storing on return 
    }
    void unionByRank(int u,int v){
        //ultp is ultimate parent
        int ultp_u=findParent(u);
        int ultp_v=findParent(v);
        if(ultp_u==ultp_v)return;//same parent then no change to be done
        if(rank[ultp_u]<rank[ultp_v]){
            parent[ultp_u]=ultp_v;//smaller attached to larger no increase of rank
        }
        else if(rank[ultp_v]<rank[ultp_u]){
            parent[ultp_v] = ultp_u;
        }
        else{//on same rank
            parent[ultp_v] = ultp_u;//attach any
            rank[ultp_u]++;
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
       int n=accounts.size();
       DisjointSet ds(n);
       //step 1:Making the disjoint set and connecting to the ultimate parent
       unordered_map<string,int>mapMailNode;
       for(int i=0;i<n;i++){
           for(int j=1;j<accounts[i].size();j++){
               string mail=accounts[i][j];
               if(mapMailNode.find(mail)==mapMailNode.end())//not present
               mapMailNode[mail]=i;
               else{//already present
                   ds.unionByRank(mapMailNode[mail],i);
               }
           }
       }
       //step 2:merging the mails according to their disjoint set number
       vector<string>mergeMail[n];
       for(auto x:mapMailNode){
           string mail=x.first;int node=x.second;
           int ultimate_node=ds.findParent(node);
           mergeMail[ultimate_node].push_back(mail);
       }
       //step 3:Rearrange in sorted order for ans
       vector<vector<string>>ans;
       for(int i=0;i<n;i++){
           if(mergeMail[i].size()==0)continue;
           sort(mergeMail[i].begin(),mergeMail[i].end());
           vector<string>temp;
           temp.push_back(accounts[i][0]);//name
           //all name's mail
           for(auto mail:mergeMail[i])
           temp.push_back(mail);
           //final push temp into ans
           ans.push_back(temp);
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends