#include <iostream>
#include <stack>
using namespace std;
void deleteMiddle(stack<int> &inputStack, int N)
{

    // Note top start from arr[0];
    if (N == 0) // stack is empty
    {
        inputStack.pop();
        return;
    }

    int size = N + 1;
    int mid = size / 2;
    if (size % 2 == 0)
    {
        mid = size / 2 - 1;
    }
    int count = 0;
    stack<int> element;
    while (count <= mid)
    {
        if (count == mid)
        {
            inputStack.pop();
            break;
        }
        element.push(inputStack.top());
        inputStack.pop();
        count++;
    }
    while (!element.empty())
    {
        inputStack.push(element.top());
        element.pop();
    }
}
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<int> ans;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(')
        //         if(expression[i]==('{'||'['||'('))
        {
            ans.push(expression[i]);
        }
        if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')')
        //         else if(expression[i]==('}'||']'||')'))
        {
            if (ans.empty())
            {
                return false;
            }
            if ((expression[i] == '}' && ans.top() == '{') || (expression[i] == ']' && ans.top() == '[') || (expression[i] == ')' && ans.top() == '('))
            {
                ans.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return ans.empty();
}
int main()
{
    string str = "}";
    cout << isValidParenthesis(str);
    //*************************
    // stack<int> s;
    // stack<int> e;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    // s.push(6);
    // deleteMiddle(s, 5);
    // while (!s.empty())
    // {
    //     cout << s.top() << endl;
    //     s.pop();
    // }

    return 0;
}