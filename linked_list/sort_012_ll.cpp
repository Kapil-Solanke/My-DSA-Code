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
void count(Node *&head)
{
    map<int, int> visited;
    visited[0] = 0;
    visited[1] = 0;
    visited[2] = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        visited[temp->data]++;
        temp = temp->next;
    }
    cout << visited[0] << endl;
    cout << visited[1] << endl;
    cout << visited[2] << endl;
    Node *start = head;
    while (visited[0] != 0)
    {
        start->data = 0;
        start = start->next;
        visited[0]--;
    }
    while (visited[1] != 0)
    {
        start->data = 1;
        start = start->next;
        visited[1]--;
    }
    while (visited[2] != 0)
    {
        start->data = 2;
        start = start->next;
        visited[2]--;
    }
    print(head);
}
Node *getmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL||fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        if (fast->next != NULL)
        {
            fast = fast->next;
        }
    }
    // cout << slow->data << endl;
    return slow;
}

int main()
{
    Node *head = new Node(1);
    // print(head);
    insert_at_Tail(head, 2);
    insert_at_Tail(head, 3);
    insert_at_Tail(head, 1);
    insert_at_Tail(head, 1);
    // count(head);
    // Node *mid = getmid(head);
    getmid(head);
    // cout << mid->data << endl;
    return 0;
}