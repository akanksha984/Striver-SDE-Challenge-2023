/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if (head==NULL || head->next==NULL || k==0)return head;
     Node* newHead= head;
     int len=0;
     Node* curr= head;
     while (curr){
          len++;
          curr= curr->next;
     }
     if (k==len)return head;
     k= k%len;
     k= len-k;
     curr= head;
     while (curr->next){
          curr= curr->next;
     }
     curr->next= head;
     while (k--){
          curr= curr->next;
     }
     head= curr->next;
     curr->next=NULL;
     return head;
}
