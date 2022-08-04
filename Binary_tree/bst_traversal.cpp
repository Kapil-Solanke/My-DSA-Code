#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class node
{
public:
    // Note- Make variables public so that other function can access them, by Default variables are private.
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildtree(node *root)
{
    cout << "enter the data" << endl;
    int data;
    cin >> data;

    root = new node(data);
    if (data == -1)
        return NULL;
    // for inserting in left
    cout << "enter the data in left" << endl;
    root->left = buildtree(root->left);

    // for inserting in right
    cout << "enter the data in right" << endl;
    root->right = buildtree(root->right);
    return root;
}
vector<int> vertical_order(node *root)
{
    map<int,map<int,vector<int> > >nodes;
    queue<pair<node*,pair<int,int> > >q;    
}
int sum(node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL&&root->right==NULL)
        return root->data;
    int left=sum(root->left);
    int right=sum(root->right);
    int ans=root->data+max(left,right);
    return ans;
}
int main()
{
    node *root = NULL;
    root = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    return 0;
}