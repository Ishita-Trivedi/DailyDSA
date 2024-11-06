class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        vector<int>bitscount(n,0);
        vector<pair<int,int>>vec;
        for(int i=0;i<=8;i++){
            int mask=1<<i;
            for(int j=0;j<n;j++){
            if(nums[j]&mask)
            bitscount[j]++;
            }
        }
        if(n==2){
            if(nums[0]>nums[1]&&bitscount[0]!=bitscount[1])
            return false;
            return true;
        }
        for(int i=0;i<n;i++)
            vec.push_back({nums[i],bitscount[i]});
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i-1;j++){
                if(vec[j].first>vec[j+1].first&&vec[j].second==vec[j+1].second)
                swap(vec[j],vec[j+1]);
            }
        }
        for(int i=1;i<n-1;i++){
            if(vec[i].first>=vec[i-1].first&&vec[i].first<=vec[i+1].first)
            continue;
            return false;
        }
        return true;
    }
};