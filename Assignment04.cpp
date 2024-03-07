#include<bits/stdc++.h>
using namespace std;

class h
{
    public:
    int num,par;
    string person;
};
class hashTable
{
    public:
    int size=0;
    array<h,10>a;
    hashTable()
    {
        for(int i=0;i<10;i++) a[i].num=i,a[i].person="";
    }

    void insert(int data, string name)
    {
        if(size==10) 
        {
            cout<<"Hash Table is full";
            return;
        }
        int key=data%10;
        int collision=0;
        if(a[key].person=="")
        {
            a[key].person=name;
            a[key].par=data;
        }
        else
        {
            int i=key;
            while(a[i].person != ""){
                i = (i+1)%10;
                collision++;
            }
            
            a[i].par=data;
            a[i].person = name;
        }
        size++;
    }
    
    void insert2(int data, string name)
    {
        if(size==10) 
        {
            cout<<"Hash Table is full";
            return;
        }
        int key=data%10;
        int collision=0;
        if(a[key].person=="")
        {
            a[key].person=name;
            a[key].par=data;
        }
        else
        {
            if(a[key].par%10!=key) swap(a[key].person,name);
            int i=key;
            while(a[i].person != "")
            {
                i = (i+1)%10;
                collision++;
            }
            a[i].person = name;
            a[i].par=data;
        }
        size++;
    }

    void display()
    {
        for(int i=0;i<10;i++)
        {
            cout<<a[i].num<<"->"<<a[i].person<<" "<<endl;
        }
        cout<<endl;
    }

    void find(int contact,string name)
    {
        int key=contact%10;
        int comp=1;
        if(a[key].person==name)
        {
            cout<<"Found with comparisons="<<comp<<endl;
            return;
        }
        else
        {
            int i=key+1;
            while(i!=key)
            {
                comp++;
                if(a[i].person==name) break;
                i=(i+1)%10;
            }
            cout<<"Found with comparisons="<<comp<<endl;
        }
    }
};

int main()
{
    hashTable ho;
    hashTable i;
    ho.insert(13,"abc");
    i.insert2(13,"abc");
    ho.insert(13,"bcd");
    i.insert2(13,"bcd");
    ho.insert(14,"xyz");
    i.insert2(14,"xyz");
    ho.display();
    i.display();
    
    ho.find(13,"xyz");
    i.find(14,"xyz");
    return 0;
}
