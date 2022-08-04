#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class graph
{
public:
    unordered_map<int, list<int>> adj;
    void insert(int u, int v, bool direction)
    {
        // direction 0 -> undirected
        // direction 1 -> directed
        // edge from u -> v
        adj[u].push_back(v);
        // if undirected both link
        if (direction == 0)
            adj[v].push_back(u);
    }

    void print_graph()
    {
        for (auto i : adj)
        {
            cout << i.first << " ->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};
int main()
{
    graph g;
    cout << "no of nodes" << endl;
    int n;
    cin >> n; //5
    cout << "no  of edge" << endl;
    int m;
    cin >> m; //6
    /*
0 1
1 2
2 3
3 1
3 4
0 4
    */
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.insert(u, v, 0);
    }
    g.print_graph();
    return 0;
}