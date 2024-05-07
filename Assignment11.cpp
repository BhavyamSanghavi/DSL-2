#include <iostream>
#include <fstream>
using namespace std;

class student
{
    int roll_no;
    string name;
    char div;
    string add;
    public:
    student()
    {
        roll_no=0;
        name="";
        div=' ';
        add="";
    }
    
    void display(student &s,int n);
    void search(int x,student &s);
    void delete1(int x,student &s,int& n);
};


void student::display(student &s,int n)
{
    fstream in;
    in.open("file1.txt",ios::in);
    for(int i=0;i<n;i++)
    {
        if(in.eof())
        {
            break;
        }
        in>>s.roll_no;
        in>>s.name;
        in>>s.div;
        in>>s.add;
        
        cout<<s.roll_no<<" "<<s.name<<" "<<s.div<<" "<<s.add<<endl;
    }
    in.close();
}

void student::search(int x,student &s)
{
    fstream in;
    in.open("file1.txt",ios::in);
    while(1)
    {
        in>>s.roll_no;
        in>>s.name;
        in>>s.div;
        in>>s.add;
        if(s.roll_no==x)
        {
            cout<<s.roll_no<<" "<<s.name<<" "<<s.div<<" "<<s.add<<endl;
            break;
        }
        if(in.eof())
        {
            cout<<"Record not found"<<endl;
            break;
        }
    }
    in.close();
}

void student::delete1(int x,student &s,int& n)
{
    student arr[n];
    fstream in;
    in.open("file1.txt",ios::in);
    for(int i=0;i<n;i++)
    {
        in>>s.roll_no;
        in>>s.name;
        in>>s.div;
        in>>s.add;
        arr[i]=s;
    }
    in.close();
    in.open("file1.txt",ios::out | ios::trunc);
    for(int i=0;i<n;i++)
    {
        if(arr[i].roll_no==x)
        {
            continue;
        }
        else
        {
            in<<arr[i].roll_no<<" "<<arr[i].name<<" "<<arr[i].div<<" "<<arr[i].add<<endl;
            cout<<arr[i].roll_no<<" "<<arr[i].name<<" "<<arr[i].div<<" "<<arr[i].add<<endl;
        }
    }
    n--;
    in.close();

}

int main()
{
    student s1;
    int c=1;
    int n;
    fstream myfile;
    while(c>0)
    {
        cout<<"MENU"<<endl;
        cout<<"1.Add record to file"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.Search"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"Enter your choice:";
        cin>>c;
        if(c==1)
        {
            myfile.open("file1.txt",ios::out);
            cout<<"Enter number of entries:";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                int roll_no;
                string name;
                char div;
                string add;
                cout<<"Enter roll_no:";
                cin>>roll_no;
                cout<<"Enter name:";
                cin>>name;
                cout<<"Enter division:";
                cin>>div;
                cout<<"Enter address:";
                cin>>add;
                myfile<<roll_no<<" "<<name<<" "<<div<<" "<<add<<endl;
            }
            myfile.close();
        }
        else if(c==2)
        {
            s1.display(s1,n);
        }
        else if(c==3)
        {
            int x;
            cout<<"Enter the roll no to search:";
            cin>>x;
            s1.search(x,s1);
        }
        else if(c==4)
        {
            int x;
            cout<<"Enter roll no to delete:";
            cin>>x;
            s1.delete1(x,s1,n);
        }
    }
    return 0;
}
