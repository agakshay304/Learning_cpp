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

bool identical(node* root1,node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    else if(root1==NULL || root2==NULL)
    {
        return false;
    }
    else
    {
        bool cond1=root1->data==root2->data;
        bool cond2=identical(root1->left,root2->left);
        bool cond3=identical(root1->right,root2->right);

        if(cond1 && cond2 && cond3)
        {
            return true;
        }
    }
    return false;
    
}

int main()
{
    node* root1=new node(1);
    root1->left=new node(2);
    root1->right=new node(3);
    root1->left->right=new node(4);
    root1->right->right=new node(5);
    root1->left->right->left=new node(6);
    root1->left->right->right=new node(7);

    node* root2=new node(1);
    root2->left=new node(2);
    root2->right=new node(9);
    root2->left->right=new node(4);
    root2->right->right=new node(5);
    root2->left->right->left=new node(6);
    root2->left->right->right=new node(7);

    cout<<identical(root1,root2);

}