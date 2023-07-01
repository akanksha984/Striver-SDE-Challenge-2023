/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
    char data;
    TrieNode* link[26];
    bool isword;
    TrieNode(){
        data='/';
        isword=false;
    }
    TrieNode(char data){
        this->data=data;
    }
};
class Trie{
    private: TrieNode* root;
    TrieNode* getNode(string word){
        TrieNode* p = root;
        for(int i=0;i<word.size();i++){
            if(p->link[word[i]-'a']==NULL) return NULL;
            p=p->link[word[i]-'a'];
        }
        return p;
    }
    public:
    Trie(){
        root=new TrieNode('/');
    }

    void insert(string word){
        TrieNode* p= root;
        for(int i=0;i<word.size();i++){
            if(p->link[word[i]-'a']==NULL){
                p->link[word[i]-'a']= new TrieNode(word[i]);
            }
            p=p->link[word[i]-'a'];
        }
        p->isword=true;
    }

    bool search(string word){
           TrieNode* p = getNode(word);
           return p!=NULL && p->isword;
    }
    bool startsWith(string prefix){
            TrieNode* p = getNode(prefix);
            return p!=NULL;
    }
};
