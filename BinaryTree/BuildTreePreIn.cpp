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

int search(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
    return -1;
}
node* buildtree(int preorder[],int inorder[],int start,int end)
{
    static int idx=0;
    //This is Base Case
    if(start>end)
    {
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    node* n=new node(curr);

    int pos=search(inorder,start,end,curr);
    //When start is at leaf position.
    if(start==end)
    {
        return n;
    }
    n->left=buildtree(preorder,inorder,start,pos-1);
    n->right=buildtree(preorder,inorder,pos+1,end);
    return n;
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
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    node* build=buildtree(preorder,inorder,0,4);
    inorderdisplay(build);


}