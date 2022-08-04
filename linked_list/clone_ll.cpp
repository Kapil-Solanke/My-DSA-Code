#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *arb;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->arb = NULL;
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
    Node *n = new Node(data);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = n;
        n->next = NULL;
    }
}
Node *copyList(Node *head)
{
    // Write your code
    map<Node *, Node *> visited;
    Node *copy = new Node(head->data);
    // Node *copy=NULL;// stores head of copied list
    Node *ans = copy; // stores head of copied list
    Node *temp = head->next;
    // create copy of linked list with next pointer
    while (temp != NULL)
    {
        insert_at_Tail(copy, temp->data);
        // visited[temp]=copy;
        temp = temp->next;
        copy = copy->next;
    }
    Node *org_head = head;
    Node *copied = ans;
    while (org_head != NULL)
    {
        visited[org_head] = copied;
        org_head = org_head->next;
        copied = copied->next;
    }
    // Now random pointer is remaining
    Node *copied_head = ans;
    Node *temp2 = head;
    while (temp2 != NULL)
    {
        copied_head->arb = visited[temp2->arb];
        copied_head = copied_head->next;
        temp2 = temp2->next;
    }

    return ans;
}
Node *clone(Node *head)
{
    Node *copy = new Node(head->data);
    // Node *copy=NULL;// stores head of copied list
    Node *ans = copy; // stores head of copied list
    Node *temp = head->next;
    // create copy of linked list with next pointer
    while (temp != NULL)
    {
        insert_at_Tail(copy, temp->data);
        // visited[temp]=copy;
        temp = temp->next;
        copy = copy->next;
    }
    //Making links in originaland copy
    Node *org_head = head;
    Node *clone_head = ans;
    while (org_head != NULL)
    {
        Node *temp1 = org_head->next;
        Node *temp2 = clone_head->next;
        org_head->next = clone_head;
        clone_head->next = temp1;
        org_head = temp1;
        clone_head = temp2;
    }

    // Method 1 
    //  temp = head;
    //  while (temp != NULL && temp->next != NULL)
    //  {
    //      if (temp->arb != NULL)
    //      {
    //          temp->next->arb = temp->arb->next;
    //      }
    //      temp = temp->next->next;
    //  }

    // Method 2
    org_head = head;
    clone_head = ans;
    while (clone_head->next != NULL && clone_head != NULL)
    {
        if (org_head->arb != NULL)
        {
            clone_head->arb = org_head->arb->next;
        }
        org_head = org_head->next->next;
        clone_head = clone_head->next->next;
    }
    // Break links in original and copy 
    org_head = head;
    clone_head = ans;
    while (org_head != NULL && clone_head != NULL)
    {
        Node *temp1 = clone_head->next;
        if (temp1 == NULL)
        {
            org_head->next = NULL;
            clone_head->next = NULL;
            break;
        }
        Node *temp2 = temp1->next;
        org_head->next = temp1;
        clone_head->next = temp2;
        org_head = temp1;
        clone_head = temp2;
    }
    return ans;
}
int main()
{
    Node *head = new Node(1);
    insert_at_Tail(head, 2);
    insert_at_Tail(head, 3);
    insert_at_Tail(head, 4);
    // Node *ans = copyList(head);
    // print(ans);

    Node *cloneans = clone(head);
    print(cloneans);

    // cout << head->next << endl;
    // cout << head->arb << endl;
    // insert_at_Tail(head, 2);
    // print(head);
    // Node *head1 = NULL;
    // insert_at_Tail(head1, 3);
    // insert_at_Tail(head1, 4);
    // insert_at_Tail(head1, 5);
    // print(head1);
    return 0;
}