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
bool detectloop_2ptr(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *fast = head;
    Node *slow = head;
    bool ans = false;
    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        if (fast == slow)
        {
            ans = true;
            break;
        }
    }
    return ans;
}
bool detect_loop(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<Node *, bool> visited;
    Node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            cout<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
int main()
{
    Node *head = new Node(3);
    print(head);
    insert_at_Tail(head, 4);
    print(head);
    insert_at_Tail(head, 5);
    print(head);
    insert_at_Tail(head, 6);
    print(head);
    insert_at_Tail(head, 7);
    print(head);
    Node *loop = giveadress(head, 5);
    // cout<<loop->data<<endl;
    Node *end = giveadress(head, 7);
    end->next = loop;
    cout<<detect_loop(head);
    return 0;
}