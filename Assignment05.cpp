#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    string value;
    Node* next=NULL;
    Node(int k,string data)
    {
        key=k;
        value=data;
        next=NULL;
    }
};

class HashMap
{
public:
    Node* a[10];
    
    HashMap()
    {
        for(int i=0;i<10;i++) a[i]=NULL;
    }

    void insert(int k, string data)
    {
        int k1=k%10;
        Node*temp=a[k1];   
        if(a[k1]==NULL)
        {
            a[k1]=new Node(k,data);
            return;
        }
        while(temp->next!=NULL) temp=temp->next;
        temp->next=new Node(k,data);
    }

    void deleteKey(int key )
    {
        int k=key%10;
        Node* temp=a[k];
        if(temp->key==key)
        {
            a[k]=temp->next;
            delete temp;
            return;
        }
        while(temp->next->key!=key) temp=temp->next;
        Node* delNode=temp->next;
        temp->next=temp->next->next;
        delete delNode;
    }

    void search(int key)
    {
        int k=key%10;
        Node* temp=a[k];
        while(temp!=NULL && temp->key!=key) temp=temp->next;
        if(temp==NULL)  cout<<"Key not present in the Hash Map"<<endl;
        else  cout<<temp->key<<"->"<<temp->value<<endl;
    }

    void print()
    {
        for(int i=0;i<10;i++)
        {
            Node* temp=a[i];
            cout<<i<<"->"<<"  ";
            while(temp!=NULL)
            {
                cout<<temp->key<<"  "<<temp->value<<"  ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    
};

int main()
{
    HashMap b;
    b.insert(1,"Neel");
    b.insert(2,"Bhavyam");
    b.insert(69,"Pari");
    b.insert(96,"Mal");
    b.insert(32,"Kullu");
    b.print();
    b.deleteKey(32);
    b.print();
    b.search(2);
    b.search(34);
    return 0;
}
