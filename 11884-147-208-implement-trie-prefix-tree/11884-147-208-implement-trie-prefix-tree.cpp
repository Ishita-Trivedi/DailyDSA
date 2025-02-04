class TrieNode{
    public:
    char data;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char d){
        data=d;
        isTerminal=false;
        for(int i=0;i<26;i++)
        children[i]=nullptr;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
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
    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0)
        return root->isTerminal;
        int idx=word[0]-'a';
        if(root->children[idx])
        return searchUtil(root->children[idx],word.substr(1));
        else
        return false;
    }
    bool search(string word) {
        return searchUtil(root,word);
    }
    bool startUtil(TrieNode* root,string word){
        if(word.length()==0)
        return true;
        int idx=word[0]-'a';
        if(root->children[idx])
        return startUtil(root->children[idx],word.substr(1));
        else
        return false;
    }
    bool startsWith(string prefix) {
        return startUtil(root,prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */