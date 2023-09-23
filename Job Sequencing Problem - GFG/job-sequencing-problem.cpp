//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    bool compare(Job a,Job b){
        return a.dead>b.dead;
    };
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       sort(arr, arr + n,
		[](Job a, Job b) { return a.dead < b.dead; });
        int profit=0,jobs=0;
        priority_queue<int>pq;
        for(int i=n-1;i>=0;i--){
            int slots=0;
            if(i==0)
            slots=arr[i].dead;
            else
            slots=arr[i].dead-arr[i-1].dead;
            pq.push(arr[i].profit);
            while(slots&&!pq.empty()){
                int t=pq.top();pq.pop();
                slots--;
                profit+=t;
                jobs++;
            }
        }
        return {jobs,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends