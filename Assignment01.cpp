#include <iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node*left;
        node*right;

        node(int d)
        {
            data=d;
            left=NULL;
            right=NULL;
        }
};

class binarytree
{
public:
    node*root=NULL;
    void insert()
    {
        cout<<"Enter data=";
        int d; cin>>d;
        node* newnode=new node(d);
        node*temp=root;
        if(root==NULL)
        {
            root=newnode;
            return;
        }
        while(temp->left!=NULL || temp->right!=NULL)
        {
            cout<<"Enter direction(l/r)=";
            char dir; cin>>dir;
            if(dir=='l')
            {
                if(temp->left==NULL)
                {
                    temp->left=newnode;
                    return;
                }
                temp=temp->left;
            }
            else
            {
                if(temp->right==NULL)
                {
                    temp->right=newnode;
                    return;
                }
                temp=temp->right;
            }
        }
        cout<<"Enter direction(l/r)=";
        char dir; cin>>dir;
        if(dir=='l') temp->left=newnode;
        else temp->right=newnode;
    }

    void levelorder(node*temp)
    {
        queue<node*>q;
        q.push(root);
        q.push(NULL);

        while(!q.empty())
        {
            node*temp=q.front();    q.pop();
            if(temp==NULL)
            {
                cout<<endl;
                if(!q.empty())q.push(NULL);
            }
            else
            {
                cout<<temp->data<<"  ";
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
    }
//solution a -> traversals (recursive and iterative)
    void inorderRecursion(node* temp)
    {
        if(temp==NULL) return;
        inorderRecursion(temp->left);
        cout<<temp->data<<"  ";
        inorderRecursion(temp->right);
    }
    void preorderRecursion(node* temp)
    {
        if(temp==NULL) return;
        cout<<temp->data<<"  ";
        preorderRecursion(temp->left);
        preorderRecursion(temp->right);
    }
    void postorderRecursion(node* temp)
    {
        if(temp==NULL) return;
        postorderRecursion(temp->left);
        postorderRecursion(temp->right);
        cout<<temp->data<<"  ";
    }
    
    void preorderIterative(node* temp)
    {
        if(temp==NULL) return ;
        stack<node*>s;
        s.push(temp);
        while (!s.empty())
        {
           node*curr=s.top(); s.pop();
           cout<<curr->data<<"  ";
           if(curr->right) s.push(curr->right);
           if(curr->left) s.push(curr->left);
        }
        cout<<endl;
    }
    void inorderIterative(node* temp)
    {
        if(temp==NULL) return ;
        else
        {
            stack<node*>s;
            node*curr=temp;
            while (curr!=NULL || !s.empty())
            {
                while (curr!=NULL)
                {
                    s.push(curr);
                    curr=curr->left;
                }
                curr=s.top(); s.pop();
                cout<<curr->data<<"  ";
                curr=curr->right;
            }
            cout<<endl;
        }
    }
    void postorderIterative(node* temp)
    {
        stack<node*> s1,s2;
        s1.push(temp);
        while(!s1.empty())
        {
            node* curr=s1.top(); s1.pop();
            s2.push(curr);
            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }
        while(!s2.empty())
        {
            cout<<s2.top()->data<<"  ";
            s2.pop();
        }cout<<endl;
    }
    
    // solution b -> swap left and right pointers (recursive and iterative)
    void swapLeftRight(node*temp)
    {
        if(!temp) return;
        node* x=temp->left;
        temp->left=temp->right;
        temp->right=x;
        swapLeftRight(temp->left);
        swapLeftRight(temp->right);
        
    }
    void swapLeftRightIter(node*temp)
    {
        stack<node*>s;
        node*curr=temp;
        while (curr!=NULL || !s.empty())
        {
            while (curr!=NULL)
            {
                s.push(curr);
                node* x=temp->left;
                temp->left=temp->right;
                temp->right=x;
                curr=curr->left;
            }
            curr=s.top(); s.pop();
            curr=curr->right;
        }
    }
    
    //solution c -> height of tree 
    int height(node*temp)
    {
        if(!temp) return 0;
        return 1+max(height(temp->left),height(temp->right));
    }
    int heightIter(node*temp)
    {
        queue<node*>q;
        q.push(root);
        q.push(NULL);
        int height=0;

        while(!q.empty())
        {
            node*temp=q.front();    q.pop();
            if(temp==NULL)
            {
                height++;
                if(!q.empty())q.push(NULL);
            }
            else
            {
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
        }
        return height;
    }
    
    //solution d -> copy tree 
    node* copyTree(node* temp)
    {
        if(!temp) return NULL;
        node*newnode= new node(temp->data);
        newnode->left=copyTree(temp->left);
        newnode->right=copyTree(temp->right);
        return newnode;
    }
    node* copyTreeIter(node* temp)
    {
        if(temp==NULL) return NULL;
        stack<node*>s;
        s.push(temp);
        node*newnode=NULL;
        while (!s.empty())
        {
            node*curr=s.top(); s.pop();
            
            newnode= new node(temp->data);
            newnode->left=temp->left;
            newnode->right=temp->right;
            
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
        return newnode;
    }
    
    //solution e -> no. of leaves and internal nodes
    int totalNodes(node* temp)
    {
        if(!temp) return 0;
        return 1+totalNodes(temp->left)+totalNodes(temp->right);
    }
    int leafNodes(node* temp)
    {
        if(!temp) return 0;
        if(!temp->left && !temp->right) return 1;
        return leafNodes(temp->left)+leafNodes(temp->right);
    }
    int internalNodes(node* temp)
    {
        return totalNodes(temp)-leafNodes(temp);
    }
    int leafNodesIter(node* temp)
    {
        stack<node*>s;
        int leaf=0;
        node*curr=temp;
        while (curr!=NULL || !s.empty())
        {
            while (curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top(); s.pop();
            if(!curr->left && !curr->right) leaf++;
            curr=curr->right;
        }
        return leaf;
    }
    
    //solution f -> delete all nodes
    void deleteNodes(node* temp)
    {
        if(!temp) return;
        deleteNodes(temp->left);
        deleteNodes(temp->right);
        delete temp;
    }
    void deleteNodesIter(node* temp)
    {
        stack<node*> s1,s2;
        s1.push(temp);
        while(!s1.empty())
        {
            node* curr=s1.top(); s1.pop();
            s2.push(curr);
            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }
        while(!s2.empty())
        {
            node* x=s2.top();
            s2.pop();
            delete x;
        }
    }
};

int main() {
    binarytree b;
    //creation of binary tree
    while(1)
    {
        cout<<"Enter 1 to insert=";
        int op;cin>>op;
        if(op==1)b.insert();
        else    break;
    }

    //Traversals of tree
    cout<<endl<<"Constructed tree level order traversal:"<<endl;
    b.levelorder(b.root);cout<<endl<<endl;
    cout<<"Inorder Recursive:\n";
    b.inorderRecursion(b.root); cout<<endl;
    cout<<"Inorder Iterative:\n";
    b.inorderIterative(b.root); 
    cout<<"Preorder Recursive:\n"; cout<<endl;
    b.preorderRecursion(b.root);
    cout<<"Preorder Iterative:\n";
    b.preorderIterative(b.root);
    cout<<"Postorder Recursive:\n"; cout<<endl;
    b.postorderRecursion(b.root);
    cout<<"Postorder Iterative:\n";
    b.postorderIterative(b.root);

    //Swapping left and right pointers
    cout<<endl<<endl;
    b.swapLeftRight(b.root);
    cout<<"After swapping left and right pointers:\n";
    b.levelorder(b.root);
    b.swapLeftRightIter(b.root);

    //height of tree
    cout<<endl;
    int ht=b.height(b.root);
    cout<<"Height of tree="<<ht<<endl;
    ht=b.heightIter(b.root);
    cout<<"Height of tree Iterative="<<ht<<endl;
    
    //copy tree
    cout<<endl;
    cout<<"Copying tree"<<endl;
    node*copyNode=b.copyTree(b.root);
    cout<<"Address of original root="<<b.root<<endl;
    cout<<"Address of copied root="<<copyNode<<endl;
    
    //Number of leaf nodes
    cout<<endl;
    cout<<"Number of Leaf Nodes="<<b.leafNodes(b.root)<<endl;
    cout<<"Number of Leaf Nodes Iterative="<<b.leafNodesIter(b.root)<<endl;
    cout<<"Number of internal Nodes="<<b.internalNodes(b.root)<<endl;
    
    //delete all Nodes
    cout<<endl;
    cout<<"Deleting nodes";
    b.deleteNodes(b.root);
    
    return 0;
}
