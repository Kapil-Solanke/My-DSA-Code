#include <iostream>
#include <map>
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
Node *giveadress(Node *head, int val)
{
    while (head->data != val)
    {
        head = head->next;
    }
    return head;
}
Node *removeDuplicates(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // Write your code here
    map<int, bool> visited;
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        if (visited[curr->data] == true)
        {
            Node *temp = curr->next;
            prev->next = curr->next;
            curr->next = NULL;
            delete curr->next;
            curr = temp;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
int main()
{
    Node *head = new Node(1);
    print(head);
    insert_at_Tail(head, 2);
    insert_at_Tail(head, 3);
    insert_at_Tail(head, 4);
    print(head);
    Node *new_head = removeDuplicates(head);
    print(new_head);
    return 0;
}