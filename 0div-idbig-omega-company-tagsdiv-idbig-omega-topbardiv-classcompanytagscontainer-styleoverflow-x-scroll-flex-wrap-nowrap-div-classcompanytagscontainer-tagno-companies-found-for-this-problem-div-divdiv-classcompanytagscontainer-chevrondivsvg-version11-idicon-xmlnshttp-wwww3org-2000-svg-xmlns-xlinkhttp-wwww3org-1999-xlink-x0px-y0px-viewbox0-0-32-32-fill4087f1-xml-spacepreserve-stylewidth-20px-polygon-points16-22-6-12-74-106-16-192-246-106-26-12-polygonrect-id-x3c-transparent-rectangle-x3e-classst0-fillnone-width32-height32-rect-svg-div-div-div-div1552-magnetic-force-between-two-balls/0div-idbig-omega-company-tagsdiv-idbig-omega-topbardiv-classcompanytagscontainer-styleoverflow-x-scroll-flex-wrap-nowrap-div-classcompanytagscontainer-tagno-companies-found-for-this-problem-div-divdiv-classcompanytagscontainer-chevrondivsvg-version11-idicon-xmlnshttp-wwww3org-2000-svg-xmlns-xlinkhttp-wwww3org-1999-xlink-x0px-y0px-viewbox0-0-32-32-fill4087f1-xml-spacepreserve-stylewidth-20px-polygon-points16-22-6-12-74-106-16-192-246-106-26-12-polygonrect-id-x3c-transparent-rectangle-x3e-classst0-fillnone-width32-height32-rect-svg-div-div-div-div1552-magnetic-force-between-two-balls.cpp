class Solution {
public:
    bool isPossible(int d,vector<int>& position, int m){
        m--;int pos=position[0]+d,i=1,n=position.size();
        while(i<n&&m){
            if(position[i]>=pos){
                m--;
                pos=position[i]+d;
            }
            i++;
        }
        return m==0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size(),l=1,h=position[n-1]-position[0],ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(mid,position,m)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else
            h=mid-1;
        }
        return ans;
    }
};