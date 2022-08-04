#include <iostream>
#include <vector>
using namespace std;
void subset(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = str[0];
    cout <<"ch ="<< ch << endl;
    string ros = str.substr(1);
    subset(ros, ans);
    subset(ros, ans + ch);
}
vector<int> subset(vector<int> str, vector<int> &ans)
{
    if (str.size() == 0)
    {
        // cout << ans << endl;
        return ans;
    }
    int ch = str[0];
    str.erase(str.begin());
    vector<int> ros = str;
    return subset(ros, ans);
    ans.push_back(ch);
    return subset(ros, ans);
}
int main()
{
    // int arr[] = {1, 2, 3};
    // int size = sizeof(arr) / sizeof(int);
    string str = "123";
    subset("abc", "");
    // vector<int> nums = {1, 2, 3};
    // vector<int> ans;
    // ans = subset(nums, ans);
    // cout<<ans[0]<<endl;
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << endl;     
    // }
    // for (int i = 0; i < print.size(); i++)
    // {
    //     cout << print[i] << endl;
    // }
    return 0;
}