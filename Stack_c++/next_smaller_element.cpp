#include <iostream>
#include <iostream>
#include <stack>
using namespace std;
void smallest(stack<int> &s, int x)
{
    if (s.empty())
    {
        return;
    }
}
int main()
{
    stack<int> s;
    s.push(-1);
    int arr[] = {12, 3, 4, 5, 8, 34};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = size - 1; i >= 0; i--)
    {
        if (s.top() > arr[i])
        {

            while (s.top() >= arr[i])
            {
                s.pop();
            }
            s.push(arr[i]);
        }
    }
    while (!s.empty() && s.top())
    {
        cout << s.top() << " ";
        s.pop();
    }
    // cout<<smallest(s,s.top());
    return 0;
}