class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int l1=s1.length(),l2=s2.length(),l3=s3.length(),ans=-1;
        for(int i=0;i<min({l1,l2,l3});i++){
            string p1,p2,p3;
            p1=s1.substr(0,i+1);
            p2=s2.substr(0,i+1);
            p3=s3.substr(0,i+1);
            if(p1==p2&&p2==p3){
                ans=(l1+l2+l3)-3*(i+1);
            }
            else
            break;
        }
        return ans;
    }
};