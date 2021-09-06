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

node* sortedarraytobst(int a[],int start,int end)
{
    if(start>end)
    {
        return NULL;
    }

    int mid=(start+end)/2;
    node* root=new node(a[mid]);

    root->left=sortedarraytobst(a,start,mid-1);
    root->right=sortedarraytobst(a,mid+1,end);

    return root;
}

void preorder(node* root)
{
    if(root==NULL)
    {
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int a[]={10,20,30,40,50};
    node* root=sortedarraytobst(a,0,4);

    preorder(root);
}