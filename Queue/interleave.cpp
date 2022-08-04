#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void insertatBottom(stack<int>&s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    insertatBottom(s,x);
    s.push(num);
}
void interLeaveQueue(queue < int > & q) {
    // Write your code here.
    stack<int>s1;
    stack<int>s2;
    int mid=q.size()/2;
    for(int i=0;i<mid;i++)
    {
        int val=q.front();
        q.pop();
        insertatBottom(s1,val);
    }
    for(int i=0;i<mid;i++)
    {
        int val=q.front();
        q.pop();
        insertatBottom(s2,val);
    }
    for(int i=0;i<mid;i++)
    {
        q.push(s1.top());
        s1.pop();
        q.push(s2.top());
        s2.pop();
    }
}
int main(){
        
return 0;
}