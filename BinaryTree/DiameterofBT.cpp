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
//time complexity O(N^2)
int calculatediameter(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int lheight=calculateheight(root->left);
    int rheight=calculateheight(root->right);
    int currheight=lheight+rheight+1;

    int ldia=calculatediameter(root->left);
    int rdia=calculatediameter(root->right);

    return max(currheight,max(lheight,rheight));

}
//time complexity o(n)
int calculatediameter2(node* root,int *height)
{
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldiameter=calculatediameter2(root->left,&lh);
    int rdiameter=calculatediameter2(root->right,&rh);

    int currdiameter=lh+rh+1;
    *height=max(lh,rh)+1;

    return max(currdiameter,max(ldiameter,rdiameter));
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
        int height=0;
    cout<<calculatediameter2(root,&height)<<endl;

}