#include<iostream>

using namespace std;
struct st
{
    int data;
    struct st *left;
    struct st *right;
};
struct st *root=NULL,*temp;

void insertElements();
void preorder(struct st *);
void inorder(struct st *);
void postorder(struct st *);

int main()
{
    int ch;
    while(1)
    {
        cout<<"\n 1.Insert Elements   2.Preorder   3.Inorder   4.Postorder   5.Exit\n";
        cout<<"\n Enter your choice ";
        cin>>ch;
        switch(ch)
        {
            case 1: insertElements(); break;
            case 2: preorder(root); break;
            case 3: inorder(root); break;
            case 4: postorder(root); break;
            case 5: exit(1); break;
            default: cout<<"invalid operation";
        }
    }
}

void insertElements()
{
    struct st *nc,*pNode;
    int v;
    cout<<"\n Enter the value ";
    cin>>v;
    temp=new st;
    temp->data=v;
    
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL)
        root=temp;
    else
    {
        nc=root;
        while(nc!=NULL)
        {
            pNode=nc;
            if(v<nc->data)
            nc=nc->left;
            else
            nc=nc->right;
            }
            if(v<pNode->data)
            pNode->left=temp;
            else
            pNode->right=temp;
    }
}
void preorder(struct st *temp)
{
    if(temp!=NULL)
    {
        cout<<"  "<<temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}
void inorder(struct st *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        cout<<"  "<<temp->data;
        inorder(temp->right);
    }
}
void postorder(struct st *temp)
{
    if(temp!=NULL)
    {	
        postorder(temp->left);
        postorder(temp->right);
        cout<<"  "<<temp->data;
    }
}
