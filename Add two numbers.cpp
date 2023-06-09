/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node* anshead= new Node(-1);
    Node* ans= anshead;
    int carry=0;
    while (num1 && num2){
        int n1= num1->data;
        int n2= num2->data;
        int sm= n1+n2+carry;
        carry= sm/10; sm= sm%10;
        ans->next= new Node(sm);
        ans= ans->next;
        num1= num1->next;
        num2= num2->next;
    }
    while (num1){
        int n1= num1->data+carry;
        carry= n1/10;
        n1= n1%10;
        ans->next= new Node(n1);
        num1= num1->next;
        ans= ans->next;
    }
    while (num2){
        int n2= num2->data+carry;
        carry= n2/10;
        n2= n2%10;
        ans->next= new Node(n2);
        ans= ans->next;
        num2= num2->next;
    }
    if (carry){
        ans->next= new Node(carry);
    }
    return anshead->next;
}
