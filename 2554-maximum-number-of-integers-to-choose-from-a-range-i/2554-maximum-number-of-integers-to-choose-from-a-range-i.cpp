class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt=0,sum=0,num=1,i=0;
        sort(banned.begin(),banned.end());
        while(sum<maxSum&&num<=n){
            if(i<banned.size()&&num>=banned[i]){
                if(num==banned[i])num++;
                i++;
            }
            else{
                if((sum+num)>maxSum)return cnt;
                cout<<num<<endl;
                cnt++;
                sum+=num;
                num++;
            }
        }
        return cnt;
    }
};