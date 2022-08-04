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
void iterative_reversal(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}
void reverse_recursive(Node *&head, Node *curr, Node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    reverse_recursive(head, curr->next, curr);
    curr->next = prev;
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
int getlength(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp->data != -1)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Node *findMiddle(Node *head)
{
    // Write your code here
    int length = getlength(head);
    Node *temp = head;
    if (length % 2 == 0)
    {
        int count = length / 2;
        while (count > 0)
        {   
            count--;
            temp = temp->next;
        }
    }
    else if (length % 2 != 0)
    {
        int count = length / 2;
        while (count > 0)
        {
            count--;
            temp = temp->next;
        }
    }
    return temp;
}
int main()
{
    // Node *head =new Node(NULL);
    Node *head = new Node(1);
    insert_at_Tail(head, 2);
    print(head);
    insert_at_Tail(head, 3);
    print(head);
    insert_at_Tail(head, 4);
    print(head);
    insert_at_Tail(head, 5);
    print(head);
    insert_at_Tail(head, 6);
    print(head);
    insert_at_Tail(head, -1);
    print(head);
    cout << getlength(head) << endl;
    Node *middle = findMiddle(head);
    cout << middle->data;
    // Node *newhead = reversal(head);
    // print(newhead);
    // reverse_recursive(newhead, newhead, NULL);
    // print(newhead);
    return 0;
}