class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int>ans;
        priority_queue<vector<double>>pq;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                pq.push({arr[i]/(double)arr[j],(double)arr[i],(double)arr[j]});
                while(pq.size()>k)
                pq.pop();
            }
        }
        int a=static_cast<int>(pq.top()[1]),
        b=static_cast<int>(pq.top()[2]);
        ans={a,b};
        return ans;
    }
};