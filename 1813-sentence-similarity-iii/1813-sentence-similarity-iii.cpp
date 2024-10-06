class Solution {
public:
    vector<string>helperToWords(string& sent){
        vector<string>words;
        string word="";
        sent+=" ";
        for(char &ch:sent){
            if(ch==' '){
                if(!word.empty())
                words.push_back(word);
                word="";
            }
            else
            word+=ch;
        }
        sent.pop_back();
        return words;

    }
    bool helperCheck(vector<string>&sent1,vector<string>&sent2){
        vector<string>prefix,suffix;
        for(int i=0;i<sent1.size();i++){
            prefix.push_back(sent1[i]);
            suffix.push_back(sent1[i]);
            if(prefix==sent2||suffix==sent2)
            return true;
        }
        int start=0,n1=sent1.size(),n2=sent2.size(),end=0;
        //as n2 lesser in len cmp to n1
        while(start<n2&&sent1[start]==sent2[start])
        start++;
        while(end<n2&&sent1[n1-1-end]==sent2[n2-1-end])
        end++;
        return start+end>=n2;
    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>sent1,sent2;
        sent1=helperToWords(sentence1);
        sent2=helperToWords(sentence2);
        if(sent2.size()>sent1.size())
        swap(sent1,sent2);
        return helperCheck(sent1,sent2);
    }
};