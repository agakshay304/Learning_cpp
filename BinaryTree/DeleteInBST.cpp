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

node* inordersucc(node* root)
{
  node* curr=root;
  while(curr && curr->left!=NULL)
  {
      curr=curr->left;
  }
  return curr;
}

node* deleteinbst(node* root,int key)
{   
    //this is for just finding the key to delete.
    if(key<root->data)
    {
        root->left=deleteinbst(root->left,key);
    }
    else
    if(key>root->data)
    {
        root->right=deleteinbst(root->right,key);
    }
    //when the key in found.
    else
    {
        //case 1:When only right child or no child is present
        if(root->left==NULL)
        {
            node* temp=root->right;
            free(root);
            return temp;
        }
        //case 2:When only left child or no child is present
        else if(root->right==NULL)
        {
            node* temp=root->left;
            delete(root);
            return temp;
        }
        //case 3:When Both childs are present
        else
        {
            node* temp=inordersucc(root->right);
            root->data=temp->data;
            //This is for deleting the key after replacing with inorder successor.
            root->right=deleteinbst(root->right,temp->data);
        }
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
    root->left=new node(2);
    root->right=new node(5);
    root->left->left=new node(1);
    root->left->right=new node(3);
    root->right->right=new node(6);

    inorderdisplay(root);
    cout<<endl;
    deleteinbst(root,5);
    inorderdisplay(root);
    
    }