#include <bits/stdc++.h>
class LRUCache
{
public:
    class node{
        public:
        int key, val;
        node* next;
        node* prev;
        node(int key, int val){
            this->key= key;
            this->val= val;
            prev= NULL;
            next= NULL;
        }
    };
    node* head= new node(-1,-1);
    node* tail= new node(-1,-1);
    int cap=0;
    unordered_map<int,node*> mp;
    LRUCache(int capacity)
    {
        // Write your code here
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }

    void insertAfterHead(node* curr){
        node* nxt= head->next;
        head->next= curr;
        curr->prev= head;
        curr->next= nxt;
        nxt->prev= curr;
    }
    void deleteNode(node* curr){
        curr->prev->next= curr->next;
        curr->next->prev= curr->prev; 
    }
   
    int get(int key)
    {
        // Write your code here
        if (mp.find(key)== mp.end())return -1;
        node* value= mp[key];
        int ans= value->val;
        deleteNode(value);
        node* curr= new node(key,ans);
        insertAfterHead(curr);
        mp[key]= head->next;
        return ans;
    }

    void put(int key, int value)
    {
        // Write your code here
        // if exists
        if (mp.find(key)!=mp.end()){
            deleteNode(mp[key]);
            mp.erase(key);
        }
        // if capacity is full remove lru
        if (mp.size() == cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node* curr= new node(key,value);
        insertAfterHead(curr);
        mp[key]= head->next;
    }
};
