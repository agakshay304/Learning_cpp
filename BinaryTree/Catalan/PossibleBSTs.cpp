#include <bits/stdc++.h>
#include <vector>
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

vector<node*> buildtree(int start,int end)
{
    vector<node*> trees;
    if(start>end)
    {
        trees.push_back(NULL);
        return trees;
    }
    
    for(int i=start;i<=end;i++)
    {
        vector<node*> leftsubtree=buildtree(start,i-1);
        vector<node*> rightsubtree=buildtree(i+1,end);

        for(int j=0;j<leftsubtree.size();j++)
        {
            node* left=leftsubtree[j];
            for(int k=0;k<rightsubtree.size();k++)
            {
                node* right=rightsubtree[k];
                node* root=new node(i);
                root->left=left;
                root->right=right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<node*> totaltrees=buildtree(1,3);
    for(int i=0;i<totaltrees.size();i++)
    {
        cout<<(i+1)<<":";
        preorder(totaltrees[i]);
        cout<<endl;
    }
}