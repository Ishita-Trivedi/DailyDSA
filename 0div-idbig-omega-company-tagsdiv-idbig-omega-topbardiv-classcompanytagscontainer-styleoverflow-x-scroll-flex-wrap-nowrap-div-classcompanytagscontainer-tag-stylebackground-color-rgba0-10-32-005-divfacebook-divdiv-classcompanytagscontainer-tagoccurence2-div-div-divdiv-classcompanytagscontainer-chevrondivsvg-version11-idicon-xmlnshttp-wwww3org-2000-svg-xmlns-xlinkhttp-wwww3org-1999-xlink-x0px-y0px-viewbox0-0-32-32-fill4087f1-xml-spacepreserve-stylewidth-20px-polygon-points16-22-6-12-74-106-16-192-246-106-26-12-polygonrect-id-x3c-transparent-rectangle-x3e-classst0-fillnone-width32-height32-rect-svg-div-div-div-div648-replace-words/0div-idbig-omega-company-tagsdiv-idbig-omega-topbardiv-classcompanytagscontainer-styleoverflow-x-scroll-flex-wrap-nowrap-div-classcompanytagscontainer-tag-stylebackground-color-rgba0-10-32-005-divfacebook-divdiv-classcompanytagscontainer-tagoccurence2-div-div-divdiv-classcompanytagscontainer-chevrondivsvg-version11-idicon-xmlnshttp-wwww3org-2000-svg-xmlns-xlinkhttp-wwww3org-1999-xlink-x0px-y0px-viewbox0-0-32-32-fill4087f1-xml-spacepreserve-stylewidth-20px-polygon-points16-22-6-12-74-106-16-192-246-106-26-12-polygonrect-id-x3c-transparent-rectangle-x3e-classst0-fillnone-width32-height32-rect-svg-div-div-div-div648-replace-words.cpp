class Solution {
public:
    string helper(string deriword,vector<string>& dictionary){
        vector<string>words;
        for(string root: dictionary){
           int n=root.length();
           bool check=false;
        if(deriword.length()<root.length())check=false;
        string sub=deriword.substr(0,n);
       if(sub==root)check=true;
         if(check)
            words.push_back(root);
        }
        if(words.empty())return deriword;
        string ans=words[0];
        for(string mat:words){
            if(mat.length()<ans.length())ans=mat;
        }
        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        sentence+=" ";
        string word="",nsent="";
        for(char ch:sentence){
            if(ch==' '){
                
                string rep=helper(word,dictionary);
               
                nsent+=rep+" ";
                word="";
            }
            else
            word+=ch;
        }
        nsent.pop_back();
        return nsent;
    }
};