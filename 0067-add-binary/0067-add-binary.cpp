class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1,j=b.length()-1,carry=0;
        string ans="";
        while(i>=0||j>=0||carry!=0){
            int sum=0;
            if(i>=0)
            sum+=a[i]-'0';
            if(j>=0)
            sum+=b[j]-'0';
            sum+=carry;
            cout<<sum<<endl;
            ans=to_string((sum%2))+ans;
            carry=sum/2;
            i--;
            j--;
        }
        return ans;
    }
};