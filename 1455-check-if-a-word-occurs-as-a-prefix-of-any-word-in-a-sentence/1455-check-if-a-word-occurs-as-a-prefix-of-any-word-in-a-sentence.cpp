class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int w=1;
        string word="";
        sentence+=" ";
        for(char& ch:sentence){
            if(ch==' '){
                if(word.length()>=searchWord.length()){
                    string s=word.substr(0,searchWord.length());
                    if(s==searchWord)return w;
                }
                word="";
                w++;
            }
            else
            word+=ch;
        }
        return -1;
    }
};