class Solution {
public:
    void add(string &s){
        int i=s.length()-1,carry=1;
        while(i>=0){
            int val=carry+((s[i]=='1')?1:0);
            if(val>1){//2
                carry=1;
                s[i]='0';
            }
            else if(val){
                carry=0;
                s[i]='1';
            }
            i--;
        }
        if(carry)
        s='1'+s;
    }
    int numSteps(string s) {
        int cnt=0;
        while(s!="1"){
            cnt++;
            int i=s.length()-1;
            if(s[i]=='1')add(s);
            else
            s=s.substr(0,s.length()-1);
        }
        return cnt;
    }
};