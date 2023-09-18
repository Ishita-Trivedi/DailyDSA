class Solution {
public:
    bool check(int x,int k){
        while(x){
            k-=x&1;
            x=x>>1;
        }
        return k==0;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
       int sum=0; 
      for(int i=0;i<nums.size();i++){
          if(check(i,k))sum+=nums[i];
      }
       return sum;
    }
};