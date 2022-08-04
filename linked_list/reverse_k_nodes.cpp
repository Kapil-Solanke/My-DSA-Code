#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
void print(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}
void insert_at_Tail(Node *&head, int data)
{
    if (head == NULL)
    {
        // Node *n =new Node(data);.
        head->data = data;
        head->next = NULL;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *n = new Node(data);
        temp->next = n;
        n->next = NULL;
    }
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    //base case
    if(head==NULL)
    {
        return NULL;
    }
    //step 1- solve 1 case
    Node *prev=NULL;
    Node * curr=head;
    Node *forward=NULL;
    int count=0;
    while(curr!=NULL&&count<k)
    {
        forward=curr->next;
        // // cout<<prev->data<<endl;
        cout<<curr->data<<endl;
        cout<<forward->data<<endl;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    //after 1 case recursion will solve other;
    if(forward!=NULL)
    {
        cout<<forward->data<<endl;
        head->next=kReverse(forward,k);
    }
    return prev;
}
int main()
{
    Node *head = new Node(3);
    print(head);
    insert_at_Tail(head, 4);
    print(head);
    insert_at_Tail(head, 5);
    print(head);
    kReverse(head,2);
    // Node *newhead=kReverse(head,2);
    // print(newhead);
    return 0;
}