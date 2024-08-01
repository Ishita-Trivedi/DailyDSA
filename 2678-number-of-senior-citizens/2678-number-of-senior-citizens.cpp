class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(string s:details){
            int age=stoi(s.substr(11,2));
            cnt+=(age>60);
        }
        return cnt;
    }
};