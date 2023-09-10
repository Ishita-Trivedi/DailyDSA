class Solution {
public:
    bool possible(int days,int limit,vector<int>& weights){
        int d=0,sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>limit)return false;
            if(sum+weights[i]>limit){
                sum=weights[i];d++;
            }
            else
            sum+=weights[i];
        }
        if(sum!=0)d++;
        return d<=days;
    }
    int bsearch(int days,vector<int>&weights){
        int low=weights[0],high,mid;
        high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            mid=high-(high-low)/2;
            if(possible(days,mid,weights))high=mid-1;
            else
            low=mid+1;
        }
        return low;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        return bsearch(days,weights);
    }
};