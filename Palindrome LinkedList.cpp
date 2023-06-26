#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* getMid(LinkedListNode<int>* head){
    LinkedListNode<int>* slow=head;
    LinkedListNode<int>* fast=head;
    while (fast->next && fast->next->next){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}
LinkedListNode<int>* reverse(LinkedListNode<int>* head){
    if (head==NULL || head->next==NULL)return head;
    LinkedListNode<int>* prev= NULL;
    LinkedListNode<int>*curr= head;
    while (curr){
        LinkedListNode<int>* nxt= curr->next;
        curr->next= prev;
        prev= curr;
        curr= nxt;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if (head==NULL || head->next==NULL)return true;
    LinkedListNode<int>* mid= getMid(head);
    LinkedListNode<int>* temp= mid->next;
    LinkedListNode<int>* revHead= reverse(temp);
    mid->next= NULL;
    while (head!= NULL && revHead!= NULL){
        if (head->data != revHead->data)return false;
        head= head->next; revHead= revHead->next;
    }
    return true;
}
