#include <bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    stack<int> stk1, stk2;
    
    public:
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        stk1.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        int ele= -1;
        if (stk1.empty())return -1;
        while (!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        ele= stk2.top();
        stk2.pop();
        while (!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;
    }

    int peek() {
        // Implement the peek() function here.
        int ele= -1;
        if (stk1.empty())return -1;
        while (!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        ele= stk2.top();
        while (!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return ele;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        return stk1.empty();
    }
};
