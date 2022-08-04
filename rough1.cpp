#include <iostream>
#include<algorithm> 
#include <string>
using namespace std;

int main()
{
    // string one = "aaa";
    // string two = "bbbb"; 
     char one[] = "geeksforgeeks";
    char two[] = "gfg";
     if( lexicographical_compare(one,one+3, two,two+4))
     {

     }

    return 0;
}