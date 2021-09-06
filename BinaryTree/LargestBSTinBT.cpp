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

struct Info
{
int size;
int min;
int max;
int ans;
bool isBST;
};


Info LargestBST(node* root)
{
    if(root==NULL)
    {
        return {0,INT_MAX,INT_MIN,0,true};
    }
    if(root->left==NULL  && root->right==NULL)
    {
        return {1,root->data,root->data,1,true};
    }

    Info LeftInfo=LargestBST(root->left);
    Info Rightnfo=LargestBST(root->right);

    Info curr;
    curr.size=(1+LeftInfo.size+Rightnfo.size);

    if(LeftInfo.isBST && Rightnfo.isBST && LeftInfo.max<root->data && Rightnfo.min>root->data)
    {
        curr.min=min(LeftInfo.min,min(Rightnfo.min,root->data));
        curr.max=max(LeftInfo.min,min(Rightnfo.min,root->data));

        curr.ans=curr.size;
        curr.isBST=true;

        return curr;
    }
    curr.ans=max(LeftInfo.ans,Rightnfo.ans);
    curr.isBST=false;
    return curr;
}

int main()
{
    node* root=new node(15);
    root->left=new node(20);
    root->right=new node(30);
    root->left->left=new node(5);
    root->left->right=new node(25);

    cout<<LargestBST(root).ans<<endl;
}