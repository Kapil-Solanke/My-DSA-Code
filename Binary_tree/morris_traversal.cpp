#include <iostream>
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
node *predecessor(node *root)
{
    root = root->left;
    while (root->right != NULL && root->right != root)
    {
        root = root->right;
    }
    return root;
}
void morrisTraversal(node *root)
{
    node *curr = root;
    while (curr != NULL)
    {
        if (root->left == NULL)
        {
            cout << curr->data << endl;
            curr = curr->right;
        }
        else
        {
            node* pred=predecessor(root);
            if(pred->right==NULL)
            {
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right=NULL;
                curr=curr->right;
            }
        }
    }
}
int main()
{

    return 0;
}