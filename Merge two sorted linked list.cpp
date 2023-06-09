#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* mergedHead= new Node<int>(-1);
    Node<int>* merged= mergedHead;
    while (first && second){
        if (first->data > second->data){
            merged->next= new Node<int>(second->data);
            merged= merged->next;
            second= second->next;
        }
        else{
            merged->next= new Node<int>(first->data);
            merged= merged->next;
            first= first->next;
        }
    }
    while (first){
        merged->next= new Node<int>(first->data);
        first= first->next;
        merged= merged->next;
    }
    while (second){
        merged->next= new Node<int>(second->data);
        second= second->next;
        merged= merged->next;
    }
    return mergedHead->next;
}
