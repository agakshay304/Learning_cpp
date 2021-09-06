#include <bits/stdc++.h>
#include <queue>
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

void rightview(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            node* curr=q.front();
            q.pop();
        //Only below statement will change as compare to right view.    
            if(i==0)
            {
                cout<<curr->data<<" ";
            }

            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }

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

    rightview(root);
}