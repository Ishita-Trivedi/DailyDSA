class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       int n=arr.size();
       vector<bool>vis(n,false);
       for(int i=0;i<n;i++){
            if(!vis[i]){
                bool found=false;
                for(int j=i+1;j<n;j++){
                    if(vis[j])continue;
                    if(arr[i]==arr[j]){
                        vis[j]=true;
                        found=true;
                    }
                }
                if(!found)k--;
                if(k==0)return arr[i];
            }
       }
       return "";
    }
};