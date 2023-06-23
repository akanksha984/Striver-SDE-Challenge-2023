#include <bits/stdc++.h> 
class Queue {
public:
    int arr[10001];
    int i=0, j=0;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (i==j);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[j++]= data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if (i==j)return -1;
        return arr[i++];
    }

    int front() {
        // Implement the front() function
        if (i==j)return -1;
        return arr[i];
    }
};
