#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    vector<int> v;
    int index=0; int len=0;
    Stack(int capacity) {
        // Write your code here.
        len= capacity;
        v.resize(len,0);
    }

    void push(int num) {
        // Write your code here.
        if (index+1<=len){
            v[index]=num;
            index++;
        }
    }

    int pop() {
        // Write your code here
        if (index==0)return -1;
        return v[--index];
    }
    
    int top() {
        // Write your code here.
        if (index!=0){
            return v[index-1];
        }
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        return (index==0);
    }
    
    int isFull() {
        // Write your code here.
        return (index==len);
    }
    
};
