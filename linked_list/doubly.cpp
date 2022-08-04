#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value)
    {
        this->data = value;
        this->prev = NULL;
        this->next = NULL;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getlen(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtHead(Node *&head, int val)
{
    if (head == NULL)
    {
        Node *n = new Node(val);
        head = n;
    }
    else
    {
        Node *n = new Node(val);
        Node *temp = head;

        temp->prev = n;
        n->next = temp;
        n->prev = NULL;
        head = n;
    }
}
// Node *insertAtHead(Node *head, int data)
// {
//     Node *n = new Node(data);
//     Node *temp = head;

//     temp->prev = n;
//     n->next = temp;
//     n->prev = NULL;
//     head = n;
//     return head;
// }
void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *n = new Node(data);
        head = n;
    }
    else
    {
        Node *n = new Node(data);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->next = NULL;
        n->prev = temp;
    }
}
void insertAtPos(Node *&head, int data, int pos)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    if (pos == getlen(head))
    {
        insertAtTail(head, data);
        return;
    }
    else
    {
        Node *temp = head;
        int count = 1;
        while (count != pos - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        n->prev = temp;
        temp->next->prev = n;
        temp->next = n;
    }
}
void deleteHead(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head->next;
        // free(head);
        delete (head);
        head = temp;
        head->prev = NULL;
    }
}
void deleteTail(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete (temp->next);
    temp->next = NULL;
}
void deletePos(Node *&head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        deleteHead(head);
        return;
    }
    if (pos == getlen(head))
    {
        deleteTail(head);
        return;
    }
    else
    {
        int count = 1;
        Node *temp = head;
        while (count != pos - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *n = temp->next->next;
        delete (temp->next);
        temp->next = n;
        n->prev = temp;
    }
}
int main()
{
    // Node *head = new Node(2);
    Node *head = NULL;
    // print(head);
    insertAtHead(head, 1);
    print(head);
    insertAtHead(head, 0);
    print(head);
    insertAtTail(head, 3);
    print(head);
    insertAtTail(head, 4);
    print(head);
    // cout << getlen(head);
    insertAtPos(head, 11, 1);
    print(head);
    // deleteHead(head);
    // print(head);
    deletePos(head, 2);
    print(head);
    // deleteHead(head);
    // print(head);
    // deleteTail(head);
    // print(head);
    // free(head);

    // Node *newhead= insertAtHead(head,1);
    // print(newhead);
    // Node *newhead1= insertAtHead(newhead,0);
    // print(newhead1);
    return 0;
}