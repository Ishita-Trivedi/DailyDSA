class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int cnt=0,n=arr.size();
        for(int i=1;i<n;i++)
        arr[i]^=arr[i-1];
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j;k<n;k++){
                    int a=arr[j-1];
                    if(i>=1)
                    a^=arr[i-1];
                    int b=arr[k]^arr[j-1];
                    if(a==b)cnt++;
                }
            }
        }
        return cnt;
    }
};