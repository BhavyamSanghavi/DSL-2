#include<bits/stdc++.h>
using namespace std;
class node
{
    public:
        string key;
        string mean;
        node*left;
        node*right;

        node(string k, string m)
        {
            key=k;
            mean=m;
            left=NULL;
            right=NULL;
        }
};

class bst
{
public:
    node* insert(node*root, node*newnode)
    {
        if(root==NULL) return newnode;
        if(root->key > newnode->key) root->left=insert(root->left,newnode);
        else root->right=insert(root->right,newnode);
        return root;
    }
    
    void inorder(node*root, vector<pair<string,string>>&ino)
    {
        if(root==NULL) return;
        inorder(root->left,ino);
        ino.push_back({root->key,root->mean});
        inorder(root->right,ino);
    }
    
    void find(node*root, string findkey, int comp=1)
    {
        if(root==NULL)
        {
            cout<<"Not found after comparisons="<<comp<<endl;
            return;
        } 
        if(root->key==findkey) 
        {
            cout<<"Found after comparisons="<<comp<<endl;
            return;
        }
        if(root->key>findkey) find(root->left, findkey, comp+1);
        else find(root->right,findkey, comp+1);
    }

    node* getSuccesor(node* curr)
    {
        curr=curr->right;
        while(curr!=NULL && curr->left!=NULL)
            curr=curr->left;
        return curr;
    }
    node* deleteNode(node* root, string val)
    {
        if(root==NULL) return NULL;
        if(root->key > val)
            root->left=deleteNode(root->left,val);
        else if(root->key < val)
            root->right=deleteNode(root->right,val);
        else
        {
            if(root->left==NULL)
            {
                node* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL)
            {
                node* temp=root->left;
                delete root;
                return temp;
            }
            else
            {
                node* succ=getSuccesor(root);
                root->key=succ->key;
                root->mean=succ->mean;
                root->right=deleteNode(root->right,succ->key);
            }
        }
        return root;
    }
};


void ascending(vector<pair<string,string>>&ino)
{
    for(int i=0;i<ino.size();i++)
    {
        cout<<"Key="<<ino[i].first<<"  Meaning="<<ino[i].second<<endl;
    }
}

int main()
{
    bst b;
    node* root=NULL, *newnode=NULL;
    vector<pair<string,string>>ino;
    int op=1;
    while(op==1)
    {
        cout<<"Enter key=";
        string k; cin>>k;
        cout<<"Enter meaning=";
        string m; cin>>m;
        newnode=new node(k,m);
        root=b.insert(root,newnode);
        cout<<"Press 1 to insert";cin>>op;
    }
    
    //Printing in Ascending order 
    b.inorder(root,ino);
    cout<<"Sorted order=\n";
    ascending(ino);

    //Max and Min element
    cout<<"\nMaximum Element="<<ino[ino.size()-1].first;
    cout<<"\nMinimum Element="<<ino[0].first;

    //Finding an element
    op=1;
    while(op==1)
    {
        cout<<"Enter key to find=";
        string findkey;cin>>findkey;
        b.find(root,findkey);
        cout<<"Press 1 to find another element="; cin>>op;
    }
    return 0;
}
