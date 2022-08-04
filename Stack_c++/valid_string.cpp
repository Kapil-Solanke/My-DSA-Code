#include <iostream>
#include <stack>
using namespace std;
int findMinimumCost(string str)
{
    // Write your code here
    if(str.size()%2!=0)
    {
        return -1;
    }
    stack<char> open;
    stack<char> close;
    int cost = -1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '{')
        {
            open.push(str[i]);
        }
        else if (str[i] == '}')
        {
            if (open.empty())
            {
                close.push(str[i]);
            }
            else if ((open.top() == '{' && str[i] == '}'))
            {
                open.pop();
            }
        }
    }
    // If both empty
    if (open.empty() && close.empty())
    {
        return 0; // return cost; is also ok
    }
    // // one of two empty
    if (close.empty())
    {
        if (open.size() % 2 != 0)
        {
            return -1;
        }
        else
        {
            return open.size() / 2;
        }
    }
    if (open.empty())
    {
        if (close.size() % 2 != 0)
        {
            return -1;
        }
        else
        {
            return close.size() / 2;
        }
    }
    return (open.size() + 1) / 2 + (close.size() + 1) / 2;
}

int main()
{
    string str = "}{{{";
    // string str = "}}}}{{";
    // string str = "}}}{{{";
    // string str = "{{{{{}";
    cout << findMinimumCost(str);
    return 0;
}