#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
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
void insert_bottom(Node *&head, int data)
{
    Node *n = new Node(data);
    if (head->child == NULL)
    {
        head->child = n;
        return;
    }
    Node *temp = head;
    while (temp->child != NULL)
    {
        temp = temp->child;
    }
    temp->child = n;
}
Node *flattenLinkedList(Node *&head)
{
    // Write your code here
    Node *up = head;
    Node *bottom = head;
    while (bottom != NULL && up->next != NULL)
    {
        if (bottom->child == NULL)
        {
            Node *temp = up->next;
            if (up->next != NULL)
            {
                up->next = NULL;
            }
            // up->next = NULL;
            bottom->child = temp;
            up = temp;
        }
        bottom = bottom->child;
    }
    return head;
}
int main()
{
    Node *head = new Node(1); // head
    insert_bottom(head, 2);
    insert_bottom(head, 3);
    // cout<<head->child->data<<endl;
    // cout<<head->child->child->data<<endl;
    insert_at_Tail(head, 4); // head->next;
    insert_bottom(head->next, 5);
    insert_bottom(head->next, 6);
    // cout<<head->next->child->data<<endl;
    // cout<<head->next->child->child->data<<endl;
    insert_at_Tail(head, 7); // head->next->next
    insert_bottom(head->next->next, 8);
    insert_at_Tail(head, 9);
    print(head);
    Node *ans = flattenLinkedList(head);
    print(ans);
    return 0;
}
/*

*/