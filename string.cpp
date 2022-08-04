#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool check(char str)
{
    if ((48 <= str <= 57 || 65 <= str <= 90 || 97 <= str <= 122)&&str!=32)
    {
        return true;
    }
    return false;
}
bool checkPalindrome(string s)
{
    // Write your code here.
    // 	transform(sl.begin(), sl.end(), sl.begin(), ::tolower);
    int l = 0;
    int h = s.length() - 1;
    bool ans = 1;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    while (l <= h)
    {
        if (check(s[l])==1 && check(s[h])==1)
        {
            if (s[l] == s[h])
            {
                cout << s[l] << " ";
                cout << s[h] << " ";
                l++;
                h--;
            }
            else if (s[l] != s[h])
            {
                cout << s[l] << " ";
                cout << s[h] << " ";
                ans = 0;
                break;
            }
            continue;
        }
        else if (check(s[l]) == 0)
        {
            cout << s[l] << " ";
            l++;
        }
        else if (check(s[h]) == 0)
        {
            cout << s[h] << " ";
            h--;
        }
    }
    return ans;
}
string reverseString(string str)
{
	// Write your code here.
    if(str.length()==0)
    {
        return str;
    }
    // cout<<str[str.length()-1];
    // str.erase(str.length()-1);
    
    char ch=str[str.length()-1];
    str.erase(str.length()-1);
    string remain=reverseString(str);
    string ans= ch+remain;
    // string ans= ch+reverseString(str);

    // string ans= str[str.length()-1]+reverseString(str.erase(str.length()-1));
    // reverseString(str);
    return ans;
}

int main()
{
    string s = "N2 i&nJA?a& jnI2n";
    // int ans = checkPalindrome(s);
    // cout << ans;

    // cout<<s.substr(1,3);
    // cout<<s[s.length()-1]<<endl;
    cout<<reverseString(s);
    return 0;
}
/*
string reverseString(string str)
{
	if(str.length()==0)
    {
        return str;
    }    
    char ch=str[str.length()-1];
    str.erase(str.length()-1);
    string ans= ch+reverseString(str);
    return ans;
}
*/