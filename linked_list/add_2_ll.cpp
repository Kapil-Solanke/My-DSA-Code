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
Node *reverse(Node *&head)
{
    // when 0 node or 1 node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *newhead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
Node *addTwoLists(Node *first, Node *second)
{
    // code here
       if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    // reverse first and second
    Node *newfirst = reverse(first);
    Node *newsecond = reverse(second);
    int add=0;
    int sum=0;
    int carry = 0;
    // create new link list
    Node *ans = new Node(0);
    Node *temp = ans;// store head of ans to reverse it at last
    while (newfirst != NULL && newsecond != NULL)
    {
         add = newfirst->data + newsecond->data + carry;
         sum = add % 10;
        insert_at_Tail(ans, sum);
        carry = add / 10;
        newfirst = newfirst->next;
        newsecond = newsecond->next;
    }

    if (newfirst == NULL && newsecond != NULL)
    {
        while(newsecond!= NULL)
        {
             add = newsecond->data + carry;
            insert_at_Tail(ans,add%10);
             carry=add/10;
            newsecond = newsecond->next;
        }
        if(carry!=0)
        {
            insert_at_Tail(ans, carry);
        }
    }
    else if (newfirst != NULL && newsecond == NULL)
    {
        while(newfirst!= NULL)
        {
             add = newfirst->data + carry;
            insert_at_Tail(ans, add%10);
             carry=add/10;
            newfirst = newfirst->next;
        }
        if(carry!=0)
        {
            insert_at_Tail(ans, carry);
        }
    }
    else if(newfirst == NULL && newsecond == NULL&&carry!=0)
    {
        insert_at_Tail(ans, carry);
    }

    Node *newans = reverse(temp->next);
    return newans; 
};
Node *add_2_ll(Node *first, Node *second)
{
      if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }
    // reverse first and second
    Node *newfirst = reverse(first);
    Node *newsecond = reverse(second);
    int add=0;
    int sum=0;
    int carry = 0;
    // create new link list
    Node *ans = new Node(0);
    Node *temp = ans;// store head of ans to reverse it at last
    while (newfirst != NULL || newsecond != NULL||carry!=0)
    {
        int val1=0;
        if(newfirst!=NULL)
            val1=newfirst->data;
        int val2=0;
        if(newsecond!=NULL)
            val2=newsecond->data;
        
        add = val1+val2 + carry;
        sum = add % 10;
        insert_at_Tail(ans, sum);
        carry = add / 10;
        if(newfirst!=NULL)
            newfirst = newfirst->next;
        if(newsecond!=NULL)
            newsecond = newsecond->next;
    }
    Node *newans = reverse(temp->next);
    return newans;   
}
int main()
{
    Node *first = new Node(3);
    // Node *temp = ans;
    insert_at_Tail(first, 4);
    insert_at_Tail(first, 5);
    Node *second = new Node(9);
    insert_at_Tail(second, 5);
    insert_at_Tail(second, 5);
    Node *ans = addTwoLists(first, second);
    print(ans);
    return 0;
}