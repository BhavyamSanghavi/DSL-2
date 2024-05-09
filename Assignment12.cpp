#include <iostream>
#include <fstream>
using namespace std;

class Entry
{
    int rollNo, loc;

public:
    Entry()
    {
        rollNo = -1;
        loc = -1;
    }
    friend class Hash;
};

class Hash
{
    Entry arr[10];
    int size;

public:
    Hash()
    {
        size = 10;
        for (int i = 0; i < size; i++)
        {
            arr[i] = Entry();
        }
    }
    void insert(int rollNo, int loc)
    {
        int index = rollNo % 10;
        if (arr[index].rollNo == -1)
        {
            arr[index].rollNo = rollNo;
            arr[index].loc = loc;
        }
        else
        {
            int i = 1;
            while (i < 10)
            {
                if (arr[(index + i) % 10].rollNo == -1)
                {
                    arr[(index + i) % 10].rollNo = rollNo;
                    arr[(index + i) % 10].loc = loc;
                    break;
                }
                i++;
            }
        }
    }

    void printHashTable()
    {
        cout << endl
             << endl;
        for (int i = 0; i < size; i++)
        {
            if (arr[i].rollNo != -1)
            {
                cout << arr[i].rollNo << "  " << arr[i].loc << " at index: " << i << endl;
            }
        }
    }

    int find(int roll)
    {
        int index = roll % 10;
        if (arr[index].rollNo == roll)
        {
            cout << "\nFound at loc: " << arr[index].loc << " && index " << index << endl;
            return arr[index].loc;
        }
        else
        {
            int i = 1;
            while (i < 10)
            {
                if (arr[(index + i) % 10].rollNo == roll)
                {
                    cout << "\nFound at loc: " << arr[(index + i) % 10].loc << " && index " << (index + i) % 10 << endl;
                    return arr[(index + i) % 10].loc;
                }
                i++;
            }
        }
        cout << "\n Not Found \n";
        return -1;
    }

    friend class Student;
};

class Student
{
    int rollNo;
    string name;

public:
    Student()
    {
        rollNo = 0;
        name = "";
    }
    Student(int rollNo, string name)
    {
        this->name = name;
        this->rollNo = rollNo;
    }
    void insertInFile(Hash &obj)
    {
        int rollNo;
        cout << "\nEnter Roll No: ";
        cin >> rollNo;
        string name;
        cout << "Enter name: ";
        cin >> name;
        Student s(rollNo, name);
        fstream f;
        f.open("Records-DAF.txt", ios::app);
        f.seekp(0, ios::end);
        int loc = f.tellp();
        f << s.rollNo << "  " << s.name << endl;
        obj.insert(rollNo, loc);
        cout << "Inserted at " << loc << "  " << f.tellp();
        f.close();
    }

    void searchInFile(Hash &obj)
    {
        cout << "\nRoll No to be searched: ";
        int rollNo;
        cin >> rollNo;
        int loc = obj.find(rollNo);
        if (loc == -1)
            return;
        fstream f;
        f.open("Records-DAF.txt", ios::in);
        f.seekg(loc, ios::beg);
        Student s;
        f >> s.rollNo >> s.name;
        cout << s.rollNo << "  " << s.name << endl;
    }

    void deleteFromFile(Hash &obj)
    {
        cout << "\nRoll No to be deleted: ";
        int rollNo;
        cin >> rollNo;

        fstream f;
        f.open("Records-DAF.txt", ios::in);
        Student s[10];
        int i = 0;
        while (i < 10)
        {
            f >> s[i].rollNo >> s[i].name;
            if (f.eof())
                break;
            if (s[i].rollNo != rollNo)
                i++;
        }
        f.close();
        cout << endl;
        f.open("Records-DAF.txt", ios::out);
        Hash newTable;
        for (int loop = 0; loop < i; loop++)
        {
            cout << s[loop].rollNo << "  " << s[loop].name << endl;
            f.seekp(0, ios::end);
            int loc = f.tellp();
            f << s[loop].rollNo << "  " << s[loop].name << endl;
            newTable.insert(s[loop].rollNo, loc);
        }

        obj = newTable;
    }
};

int main()
{
    Student stud;
    Hash table;
    stud.insertInFile(table);
    stud.insertInFile(table);
    stud.insertInFile(table);
    table.printHashTable();
    stud.deleteFromFile(table);
    table.printHashTable();
    stud.deleteFromFile(table);
    table.printHashTable();
    stud.searchInFile(table);
}
