#include <iostream>
using namespace std;
bool Palindrome(string str)
{
    if (str.length() == 0)
    {
        return true;
    }
    int i = 0, j = str.length() - 1;
    if (str[i] != str[j])
    {
        return false;
    }
    i++;
    j--;
    return Palindrome(str.substr(i, j));
}
// bool Palindrome(string str, int i, int j)
// {
//     if (i > j)
//     {
//         return true;
//     }
//     if (str[i] != str[j])
//     {
//         return false;
//     }
//     i++;
//     j--;
//     return Palindrome(str, i, j);
// }
int power(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    return a * power(a, b - 1);
}

int Exponentiation(int x, int n)
{
    // Write your code here.
    int ans = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (1LL * (ans) * (x));
            cout << "ans " << ans << endl;
        }
        x = (1LL * (x) * (x));
        cout << "x " << x << endl;
        n = n >> 1;
        cout << "n " << n << endl;
    }
    return ans;
}
// int modularExponentiation(int x, int n, int m)
// {
//     // Write your code here.
//     int ans = 1;
//     while (n > 0)
//     {
//         if (n & 1)
//         {
//             ans = (1LL * (ans) * (x) % m) % m;
//             cout << "ans " << ans << endl;
//         }
//         // 		x=(1LL*(x)%m*(x)%m)%m;
//         x = (1LL * (x) * (x)) % m;
//         cout << "x " << x << endl;
//         n = n >> 1;
//         cout << "n " << n << endl;
//     }
//     return ans;
// }
int a_power_b(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ans = power(a, b >> 1);
    if (b & 0) // b is even
        return ans * ans;

    return a * ans * ans; // b is odd
}
int main()
{
    string s = "123245";
    // cout<<Palindrome(s,0,s.length()-1);
    cout << Palindrome(s) << endl;
    // cout << power(2, 3) << endl;
    // cout << a_power_b(3, 11);
    // cout << modularExponentiation(3, 3, 10);
    cout << Exponentiation(2, 3);
    return 0;
}