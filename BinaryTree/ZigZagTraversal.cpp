#include <bits/stdc++.h>
#include <stack>
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

void zigzag(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*> currlevel;
    stack<node*> nextlevel;
     bool LtoR=true;
     currlevel.push(root);

     while(!currlevel.empty())
     {
         node* temp=currlevel.top();
        currlevel.pop();

        if(temp)
        {
            cout<<temp->data<<" ";
            if(LtoR)
            {
                if(temp->left)
                {
                    nextlevel.push(temp->left);
                }
                if(temp->right)
                {
                    nextlevel.push(temp->right);
                }
            }
            else
            {
                if(temp->right)
                {
                    nextlevel.push(temp->right);
                }
                if(temp->left)
                {
                    nextlevel.push(temp->left);
                }
            }
        }
        if(currlevel.empty())
        {
            LtoR=!LtoR;
            swap(currlevel,nextlevel);
        }
     }
}

int main()
{
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->right=new node(4);
    root->right->right=new node(5);
    root->left->right->left=new node(6);
    root->left->right->right=new node(7);

    zigzag(root);
}
