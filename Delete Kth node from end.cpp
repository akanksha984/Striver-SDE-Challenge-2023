/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int k)
{
    // Write your code here.
    int len=0;
    Node* curr= head;
    if (head==NULL || head->next==NULL)return new Node(-1);
    while (curr){
        curr= curr->next;
        len++;
    }
    if (k==len)return head->next;
    len--;
    len-= k;
    curr= head;
    while (len--){
        curr= curr->next;
    }
    Node* nxt= NULL;
    if (curr->next)nxt=curr->next->next;
    curr->next->next= NULL;
    curr->next= nxt;
    return head;
}
