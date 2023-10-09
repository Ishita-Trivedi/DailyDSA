//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        // Compare the second elements of the pairs (the priority values)
        return a.second > b.second;
    }
};
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
     priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
       for(int i=0;i<n;i++)
       pq.push({start[i],end[i]});
       int ps,pe,count=1;
       auto x=pq.top();pq.pop();
       ps=x.first;pe=x.second;
       while(!pq.empty()){
            auto x=pq.top();pq.pop();
            if(x.first>pe){
                ps=x.first;
                pe=x.second;
                count++;
            }
       }
       return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends