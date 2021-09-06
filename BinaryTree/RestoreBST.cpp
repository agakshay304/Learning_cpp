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


void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void calcpointers(node* root,node** first,node** mid,node** last,node** prev)
{
    if(root==NULL)
    {
        return ;
    }
    calcpointers(root->left,first,mid,last,prev);
    if(!*first) //if first is null
    {
        *first=*prev;
        *mid=root;
    }
    else //if first has been visited
    {
        *last=root;
    }

    *prev=root;

    calcpointers(root->right,first,mid,last,prev);

}


void restoreBST(node* root)
{
    node* first=NULL;
    node* mid=NULL;
    node* last=NULL;
    node* prev=NULL;

    calcpointers(root,&first,&mid,&last,&prev);
    //case 1: When no. are not adjacent.
    if(first && last)
    {
        swap(&(first->data),&(last->data));
    }
    //case 2: When no. are adjacent.
    else
    if(first && mid)
    {
        swap(&(first->data),&(mid->data));
    }
}

void inorderdisplay(node* root)
{
    if(root==NULL)
    {
        return ;
    }

    inorderdisplay(root->left);
    cout<<root->data<<" ";
    inorderdisplay(root->right);
}

int main()
{
    node* root=new node(4);
    root->left=new node(5);
    root->right=new node(2);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);

    inorderdisplay(root);
    cout<<endl;
    restoreBST(root);

    inorderdisplay(root);
}