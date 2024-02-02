class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int>ans;
        for(int len=2;len<=s.length();len++){
            for(int start=0;start<=s.length()-len;start++){
                string temp=s.substr(start,len);
                int num=stoi(temp);
                if(num>=low&&num<=high)
                ans.push_back(num);
            }
        }
        return ans;
    }
};