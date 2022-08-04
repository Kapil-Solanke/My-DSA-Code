#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d) // constructor
    {
        this->data = d;
        this->next = NULL;
    }
    Node() // destructor
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data" << value << endl;
    }
};
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "No element in linked list" << endl;
        return;
    }
    else
    {
        Node *temp = tail;
        do
        {
            cout << tail->data << " ";
            tail = tail->next;
        } while (tail != temp);
        cout << endl;
    }
}
void insertion(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {
        Node *n = new Node(data);
        tail = n;
        n->next = n;
        return;
    }
    else
    {
        Node *temp = tail;
        while (temp->data != element)
        {
            temp = temp->next;
        }
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }
}
void deletion(Node *&tail, int val)
{
    if (tail == NULL)
    {
        return;
    }
    else
    {
        Node *prev = tail;
        while (prev->next->data != val)
        {
            prev = prev->next;
        }
        Node *curr = prev->next;
        // when only one node
        if (curr == prev)
        {
            tail=NULL;
        }
        // To handle two nodes
        else if (tail == curr)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // Node *tail = new Node(0); // not working
    Node *tail = NULL;
    // print(tail);
    insertion(tail, 0, 1);
    print(tail);
    insertion(tail, 1, 2);
    print(tail);
    // insertion(tail, 2, 3);
    // print(tail);
    // insertion(tail, 3, 4);
    // print(tail);
    // insertion(tail, 4, 5);
    // print(tail);
    deletion(tail, 1);
    print(tail);

    return 0;
}