#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
int data;
node* left;
node* right;

node(int value)
{
    data=value;
    left=NULL;
    right=NULL;
}
};

int calculateheight(node* root)
{   
    //if we r calculating wrt index return -1 else return 0.
    if(root==NULL)
    {
        return 0;
    }
    int lheight=calculateheight(root->left);
    int rheight=calculateheight(root->right);

    return max(lheight,rheight)+1;
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);

    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    cout<<calculateheight(root)<<endl;

}