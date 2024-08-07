class Solution {
private:
    string digittowords(int n){
    vector<string> ones = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
};
vector<string> tens = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};
string ans="";
    if(n>=100){
        ans+=ones[n/100];
        if(!ans.empty())
        ans+=" ";
        ans+="Hundred";
        n=n%100;
    }
    if(n>19){
        if(!ans.empty())
        ans+=" ";
        ans+=tens[n/10];
        if(!ans.empty()&&ones[n%10]!="")
        ans+=" ";
        ans+=ones[n%10];
    }
    else
   {
        if(!ans.empty()&&ones[n]!="")
        ans+=" ";
       ans+=ones[n];}
    return ans;
    }
public:
    string numberToWords(int n) {
        if(n==0)return "Zero";
        string ans="";
        vector<string>suffix={"","Thousand","Million","Billion"};
        int i=0;
        while(n){
            string ones=digittowords(n%1000);
            if(n&&!ones.empty())//if n is smaller than divisor then it would be 0 so no suffix
            ones+=" ";
            if(n%1000)
            {ones+=suffix[i];}i++;
            if(!ans.empty()&&!ones.empty())
            ans=" "+ans;
            ans=ones+ans;
            // cout<<ans<<" "<<n<<endl;
            n=n-n%1000;
            n/=1000;
        }
        while(!ans.empty()&&ans[ans.size()-1]==' ')
        ans.pop_back();
        return ans;
    }
};