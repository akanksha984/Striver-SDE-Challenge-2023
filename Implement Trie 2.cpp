#include <bits/stdc++.h> 
class Node {
    public:
    Node *child[26]={0};
    bool endOfWord;
    int cntPrefix=0, cnt=0;
};
class Trie{
    public:
    Node *root;
    Trie(){
        root=new Node();
    }
    void insert(string &s){
        Node *p=root;
        for(auto x: s) {
            int ind=x-'a';
            if(p->child[ind] ==0) p->child[ind]=new Node();
            p=p->child[ind];
            p->cntPrefix+=1;
        }
        p->endOfWord=1;
        p->cnt+=1;
    }
    int countWordsEqualTo(string &s){
        Node *p=root;
        for(auto x: s) {
            int ind=x-'a';
            if(p->child[ind] ==0) return 0;
            p=p->child[ind];
        }
        if(p->endOfWord==1) return p->cnt;
        //return 0;
    }

    int countWordsStartingWith(string &s){
        Node *p=root;
        for(auto x: s) {
            int ind=x-'a';
            if(p->child[ind] ==0) return 0;
            p=p->child[ind];
        }
        return p->cntPrefix;
    }

    void erase(string &s){
        Node *p=root;
        for(auto x: s) {
            int ind=x-'a';
            if(p->child[ind] ==0) return;
            p=p->child[ind];
            p->cntPrefix-=1;
        }
        p->endOfWord=0;
        p->cnt-=1;
    }
};
