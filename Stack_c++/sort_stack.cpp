#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int> &stack, int x)
{
    if (stack.empty())
    {
        stack.push(x);
        return;
    }
    int num = stack.top();
    stack.pop();
    insertAtBottom(stack, x);
    stack.push(num);
}
void place(stack<int> &stack, int x)
{
    if (stack.empty() || x > stack.top())
    {
        stack.push(x);
        return;
    }
    int num = stack.top();
    stack.pop();
    place(stack, x);
    stack.push(num);
}
void sortStack(stack<int> &stack)
{
    // Write your code here
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    place(stack, num);
}

int main()
{
    stack<int> stack;
    stack.push(3);
    stack.push(5);
    stack.push(9);
    stack.push(2);
    stack.push(7);

    // int num = 4;
    // place(stack, num);

    sortStack(stack);
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    return 0;
}