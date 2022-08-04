#include <iostream>
using namespace std;
string reverseString(string str)
{
    if (str.length() == 0)
    {
        return str;
    }
    // swap(str[0], str[str.length() - 1]);
    int i = 0;
    int j = str.length() - 1;
    swap(str[i], str[j]);
    reverseString(str.substr(i++, j--));
    return str;
    // return str;
}
void ans(string& str,int i,int j)
{
   if(i>j)
    {
        return ;
    }    
    swap(str[i],str[j]);
    i++;j--;
    ans(str,i,j);
}
bool check(int n)
{
    int j=n<<1;
    int ans =n^j;
    return ans;
}

int main()
{
    string s = "rabar";
    cout<<reverseString(s)<<endl;
    ans(s,0,s.length()-1);
    cout<<s;
    // cout<<check(10);
    return 0;
}