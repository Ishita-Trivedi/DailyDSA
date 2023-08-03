class Solution {
    private:
    void helper(string& digits,vector<string>&ans,string& output,int index,string mp[])
    {
        if(output.length()==digits.size())
        {
            ans.push_back(output);return;
        }
        int number =digits[index]-'0';
        string value=mp[number];
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            helper(digits,ans,output,index+1,mp);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0)
        return ans;
        string output="";
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        helper(digits,ans,output,0,mp);
        return ans;
    }
};