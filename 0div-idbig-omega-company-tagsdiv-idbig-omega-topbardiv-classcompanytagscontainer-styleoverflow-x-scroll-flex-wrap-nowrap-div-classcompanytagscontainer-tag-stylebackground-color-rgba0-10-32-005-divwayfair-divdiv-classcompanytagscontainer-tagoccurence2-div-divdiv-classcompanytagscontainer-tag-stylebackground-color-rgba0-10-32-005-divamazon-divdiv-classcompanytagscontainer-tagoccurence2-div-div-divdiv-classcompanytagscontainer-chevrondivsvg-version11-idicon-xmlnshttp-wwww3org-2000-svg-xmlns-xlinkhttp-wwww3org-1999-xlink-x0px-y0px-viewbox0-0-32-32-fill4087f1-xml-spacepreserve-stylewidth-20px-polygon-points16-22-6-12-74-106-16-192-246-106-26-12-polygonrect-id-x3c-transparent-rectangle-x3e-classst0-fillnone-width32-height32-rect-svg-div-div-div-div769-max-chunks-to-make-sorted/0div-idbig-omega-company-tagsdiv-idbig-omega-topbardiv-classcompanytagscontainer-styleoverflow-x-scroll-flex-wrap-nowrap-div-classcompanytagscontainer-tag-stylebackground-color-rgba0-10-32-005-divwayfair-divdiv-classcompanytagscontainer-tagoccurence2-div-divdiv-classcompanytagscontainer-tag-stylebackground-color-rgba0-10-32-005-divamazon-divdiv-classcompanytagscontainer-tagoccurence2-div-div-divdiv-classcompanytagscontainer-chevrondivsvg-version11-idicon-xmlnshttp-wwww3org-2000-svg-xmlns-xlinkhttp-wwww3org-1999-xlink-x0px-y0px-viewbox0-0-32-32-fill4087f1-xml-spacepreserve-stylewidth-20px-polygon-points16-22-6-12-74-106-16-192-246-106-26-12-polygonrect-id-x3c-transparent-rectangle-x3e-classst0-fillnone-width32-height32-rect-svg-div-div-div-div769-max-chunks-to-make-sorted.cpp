class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunk=0,maxi=-1;
        for(int i=0;i<arr.size();i++){
            if(maxi==-1&&arr[i]==i){
                chunk++;
            }
            else{
                maxi=max(maxi,arr[i]);
                if(maxi==i){
                    maxi=-1;chunk++;
                }
            }
        }
        return chunk;
    }
};