class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char d){
        data=d;
        for(int i=0;i<26;i++)
        children[i]=nullptr;
        isTerminal=false;
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int idx=word[0]-'a';
        TrieNode* child;
        if(root->children[idx])
        child=root->children[idx];
        else{
            TrieNode* newChild=new TrieNode(word[0]);
            root->children[idx]=newChild;
            child=newChild;
        }
        return insertUtil(child,word.substr(1));
    }
    void addWord(string word) {
        return insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        if(word[0]=='.'){
            //match ./wildcard with any char AVAILABLE  
            for(int i=0;i<26;i++){
                if(root->children[i]&&searchUtil(root->children[i],word.substr(1)))
                return true;
            }
            return false;
        }
        int idx=word[0]-'a';
        if(root->children[idx])
        return searchUtil(root->children[idx],word.substr(1));
        else
        return false;
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */