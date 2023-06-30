#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    if (head==NULL)return NULL;
    LinkedListNode<int> *curr= head;
    // insert in middle the deep copy
    while (curr){
        LinkedListNode<int> *temp= curr->next;
        LinkedListNode<int> *node= new LinkedListNode<int>(curr->data);
        curr->next= node;
        node->next= temp;
        curr= temp;
    }

    // random pointer ko point karna on right place
    curr= head;
    while (curr){
        if (curr->random==NULL){
            curr->next->random=NULL;
        }
        else{
            curr->next->random= curr->random->next;
        }
        curr= curr->next->next;
    }

    LinkedListNode<int> *copyHead= new LinkedListNode<int>(-1);
    LinkedListNode<int> *dummy= copyHead;
    curr= head;
    while (curr){
        LinkedListNode<int> *temp= curr->next;
        curr->next= curr->next->next;
        dummy->next= temp;
        curr= curr->next;
        dummy= dummy->next;
    }
    return copyHead->next;
}

