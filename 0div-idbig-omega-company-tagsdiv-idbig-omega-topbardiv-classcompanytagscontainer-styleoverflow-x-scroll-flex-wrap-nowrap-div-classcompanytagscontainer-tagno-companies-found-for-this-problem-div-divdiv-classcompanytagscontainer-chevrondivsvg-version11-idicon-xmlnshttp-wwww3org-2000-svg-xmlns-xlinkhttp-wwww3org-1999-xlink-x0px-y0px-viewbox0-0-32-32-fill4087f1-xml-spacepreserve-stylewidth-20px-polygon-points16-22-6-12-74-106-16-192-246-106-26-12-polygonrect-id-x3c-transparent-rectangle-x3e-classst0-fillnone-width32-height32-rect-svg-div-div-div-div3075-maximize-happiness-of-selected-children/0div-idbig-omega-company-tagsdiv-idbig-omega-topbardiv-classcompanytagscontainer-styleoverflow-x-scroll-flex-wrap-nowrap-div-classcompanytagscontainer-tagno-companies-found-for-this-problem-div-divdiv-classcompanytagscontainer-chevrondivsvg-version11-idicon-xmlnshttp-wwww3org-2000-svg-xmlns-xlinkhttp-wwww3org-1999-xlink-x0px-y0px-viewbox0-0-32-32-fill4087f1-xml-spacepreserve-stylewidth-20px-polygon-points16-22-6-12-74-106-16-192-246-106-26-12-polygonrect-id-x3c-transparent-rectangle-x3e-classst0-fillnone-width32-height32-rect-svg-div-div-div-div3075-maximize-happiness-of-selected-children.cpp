class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long sum=0;
for(int i=happiness.size()-k;i<happiness.size();i++){
    k--;
    sum+=max(0,happiness[i]-k);
    cout<<sum<<" "<<k<<endl;
        }
        return sum;
    }
};