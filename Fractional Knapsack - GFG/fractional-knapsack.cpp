//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans=0;
        priority_queue<pair<double,int>>pq;
        for (int i = 0; i < n; i++){
            double val=arr[i].value,wt=arr[i].weight;
            pq.push({val/wt,wt});//value per weight is pushed
        }
        while(W&&!pq.empty()){
            auto x=pq.top();pq.pop();
            if(x.second<=W){
                W-=x.second;
                ans+=x.second*x.first;
            }
            else{
                ans+=x.first*W;
                W=0;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends