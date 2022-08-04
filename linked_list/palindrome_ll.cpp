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
Node *reversal(Node *&head)
{
    // when 0 node or 1 node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newhead = reversal(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
Node *getmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // cout << slow->data << endl;
    return slow;
}
bool check_palindrome(Node*head)
{
    if(head == NULL||head->next==NULL)
    {
        return true;
    }
    Node *middle=getmid(head);
    //reverse after mid element
    Node *temp=middle->next;
    middle->next = reversal(temp);  
    //create two pointers
    Node *head1=head;
    Node *head2=middle->next;
    while(head2 != NULL)
    {
        if(head1->data!=head2->data)
        {
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    // again reverse the list to create original list

    temp=middle->next;
    middle->next = reversal(temp);
    return true;
}
int main()
{
    Node *head = new Node(1);
    // print(head);
    insert_at_Tail(head, 2);
    insert_at_Tail(head, 3);
    insert_at_Tail(head, 2);
    insert_at_Tail(head, 1);
    print(head);
    Node* mid=getmid(head);
    cout<<mid->data<<endl;
    // bool ans=check_palindrome(head);
    // cout<<ans;
    return 0;
}