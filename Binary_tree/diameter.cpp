#include <iostream>
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
int height(node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
int diameter(node *root)
{
    // code here
    if (root == NULL)
        return 0;
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;
    int ans = max(op1, max(op2, op3));
    return ans;
}
int height(node *root, int &ans)
{
    if (root == NULL)
        return 0;
    int left_height = height(root->left, ans);
    int right_height = height(root->right, ans);

    ans = max(ans, left_height + right_height + 1);
    return 1 + max(left_height, right_height);
}
int diameter(node *root)
{
    // Your code here
    if (root == NULL)
        return 0;
    int ans = 0;
    height(root, ans);
    return ans;
}
/*
pair<int,int> diameter_fast( Node* root)
{
    if(root==NULL)
     {
         pair<int,int>p=make_pair(0,0);// first represents diameter ,second represents height
         return p;
     }

     pair<int,int> left=diameter_fast(root->left);
     pair<int,int> right=diameter_fast(root->right);

     int op1=left.first; // diameter of left
     int op2=right.first;//diameter of right
     int op3=left.second+right.second+1; // diameter of left and right,calculated by
     // adding height of left +height of right +1

     pair<int,int>ans;
     ans.first=max(op1,max(op2,op3)); //for diameter
     ans.second=max(left.second,right.second)+1; //for height
     return ans;

}
int diameter(struct Node* root) {
    // code here
    return diameter_fast(root).first; // first represents diameter
}
*/
int main()
{
    node *root = NULL;
    root = buildtree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // level_order_traversal(root);

    return 0;
}