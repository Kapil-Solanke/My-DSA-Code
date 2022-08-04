#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> a;
    pair<string, int> pair1 = make_pair("meera", 3);
    a.insert(pair1);
    pair<string, int> pair2("jkj", 34);
    a.insert(pair2);

    a["baba"] = 8;
    cout << a["baba"] << endl;
    cout << a.at("baba") << endl;

    // cout<<a.at("unknown")<<endl; // will show error as "unknown" not present in the map
    cout << a["unknown"] << endl;    // this way will create unknown key with value zero a["unknown",0]
    cout << a.at("unknown") << endl; // will not show error as "unknown" created in abolve line

    // count fnxn to check wether key present in map
    cout << a.count("unknown") << endl;
    cout << a.count("adsfds") << endl;

    for (auto i : a)
    {
        cout << i.first << " " << i.second << endl;
    }
    // iterator
    unordered_map<string, int>::iterator i = a.begin();
    while (i != a.end())
    {
        cout << i->first << " " << i->second << endl;
        i++;
    }
    return 0;
}
// Map O(log(n)) , stores value in fixed order
//Unordered_map O(1), stores value in random order  