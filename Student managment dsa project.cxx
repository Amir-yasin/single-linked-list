/*group members
Amir yasin
Frezer tibebu
robel wendosen
leul mesfin*/
#include <iostream>
#include <conio.h>
using namespace std;
class linklist
{
private:
    struct node
    {
        string name, id_number, section,cgpa;
        node *next;
    };
    node *head = NULL;

public:
    int insertnode(string n, string sec, string id, string cgpa)
    {
        node *ptr = new node;
        ptr->name = n;
        ptr->section = sec;
        ptr->id_number = id;
        ptr->cgpa = cgpa;
        ptr->next = NULL;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    int display()
    {
        int i = 0;
        if (head == NULL)
        {
            cout << "\n\t\t==========   The list is empty!!!  ==========\n\n\n ";
        }
        else
        {
            cout<< "\t\t\t =========================================== \t\t\t "<<endl;
            cout<< "\t\t\t ==========  All Data of Student  ==========\t\t\t" << endl;
            cout<< "\t\t\t ===========================================\t\t\t "<<endl<<endl;
                node *temp = head;
            while (temp != NULL)
            {
                cout<< "Record of Student : " << i + 1 << endl<< endl;
                cout<< "Name of Student "<<" :\t "<<temp->name<<endl;
                cout<< "section of student "<<" :\t "<<temp->section<<endl;
                cout<< "Id of student\t "<<" :\t "<<temp->id_number<<endl;
                cout<< "Cgpa of student "<<" :\t "<<temp->cgpa<<endl;
                temp = temp->next;
                i++;
            }
        }
    }
    int deletee()
    {
        string a;
        int count = 0;
        if (head == NULL)
        {
            cout<<endl<< "\t\t==========  The list is empty!!!  ==========\n\n "<<endl;
        }
        else
        {
            cout<< "\t\t\t================================================== \t\t\t "<<endl;
            cout<< "\t\t\t==========  Delete any record of student  ==========\t\t\t "<<endl;
            cout<< "\t\t\t===================================================\t\t\t "<<endl<<endl;
        	cout<<endl<< "Enter the id number of Student : ";
            cin >> a;
            if (a == head->id_number)
            {
                node *ptr = head;
                head = ptr->next;
                delete ptr;
                count++;
            }
            else
            {
                node *prev = head;
                node *ptr = head->next;
                while (ptr != NULL)
                {
                    if (a == ptr->id_number)
                    {
                        prev->next = ptr->next;
                        cout << endl<< "\n\n\t\t\t==========  Data of " << ptr->name << " Is Deleted successefully!!!  ==========" << endl;
                        count++;
                        delete ptr;
                        break;
                    }
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
            if (count == 0)
            {
                cout << endl<< "\t\t\t==========  Student record is not found !!!  =========="<<endl;
            }
        }
    }
    int search()
    {
        string a;
        int count = 0;
        int found = 1;
        if (head == NULL)
        {
            cout<<endl<< "\t\t==========  The list is empty!!!  ==========\n\n "<<endl;
        }
        else
        {
            cout<<"\t\t\t===============================================\t\t\t "<<endl;
            cout<<"\t\t\t==========  Search record of Student  =========\t\t\t "<<endl;
			cout<<"\t\t\t===============================================\t\t\t "<<endl<<endl;
            cout<<" Enter id number For searching Data Of Student : ";
            cin>>a;
            node *ptr = head;
            while (ptr != NULL)
            {
                if (a == ptr->id_number)
                {
                    cout << "Name of Student "<<" :\t "<<ptr->name<<endl;
                    cout<< "section of student "<<" : \t "<<ptr->section<<endl;
                    cout << "Id of student\t "<<" :  \t "<<ptr->id_number<<endl;
                    cout<< "Cgpa of student "<<" :  \t "<<ptr->cgpa<<endl;
                 	count++;
                }
                ptr = ptr->next;
                found++; 
            }
            if (count == 0)
            {
                cout<<endl<< "\t\t\t=========  Student record not found !!!  ========= "<<endl;
            }
        }
    }
    int update()
    {
        string a;
        string name, id , cgpa, sec;
        int count = 0;
        int found = 1;
        if (head == NULL)
        {
            cout << endl<< "\t\t==========  The list is empty!!!  ===========\n\n "<<endl;}
        else
            {
                cout<<"\t\t\t=============================================== \t\t\t "<<endl;
                cout<<"\t\t\t==========  Update record of Student ========== \t\t\t "<<endl;
                cout<<"\t\t\t=============================================== \t\t\t "<<endl<<endl;
                cout<<"enter the value of node( cgpa of the student ) for update : ";
                cin >> a;
                node *ptr = head;
                while (ptr != NULL)
                {
                    if (a == ptr->id_number)
                    {
                        cout << endl<< "value to be updated is found : " << a << " at node " << found << endl;
                        cout << "\nEnter the new name of student : ";
                        cin >> name;
                        cout << endl<< endl<< "Enter the new section : ";
                        cin >> sec;
                        cout << endl<<endl<< "Enter the new cgpa : ";
                        cin >> cgpa;
                        cout << endl<< endl<< "Enter the new ID : ";
                        cin >> id;
                        ptr->name = name;
                        ptr->section = sec;
                        ptr->cgpa = cgpa;
                        ptr->id_number = id;
                        cout << endl<< " ==========  Record is updated successfully!!!  ========== : "<<endl<<endl;
                        count++;
                    }
                    ptr = ptr->next;
                    found++; 
                }
                if (count == 0)
                {
                    cout<<endl<<"\t\t\t=========  Student record is not found!!!  ========= "<<endl;
                }
            }
        }
        int sum()
        {
            int a;
            int sum = 0;
            if (head == NULL)
            {
                cout<<endl<<"\t\t==========  The list is empty!!!  ========== "<<endl;
            }
            else
            {
                node *ptr = head;
                while (ptr != NULL)
                {
                    sum = sum + 1;
                    ptr = ptr->next;
                }
                cout<<"\t\t\t================================================= \t\t\t "<<endl;
                cout<<"\t\t\t==========  The total Data of Student  ==========\t\t\t "<<endl;
                cout<<"\t\t\t=================================================\t\t\t "<<endl<<endl;
                cout<< endl<< "\t\t==========  Total number of students in the list is : "<<sum<<"  ========== "<<endl;
            }
        }
    };
    int main()
    {
        linklist l;
        string name, sec, cgpa, id;
        int choice, key;
        cout<< "\n\n\n\t   ==========  DATA STRUCTURE GROUP PROJECT  =========\t\t\t "<<endl;
		cout<<"\t   ==========   STUDENT MANAGEMENT SYSTEM    =========\t\t\t  "<<endl;
		cout<<"\t   ==========      SINGLY LINKED LIST        =========  "<<endl<<endl<<endl;
        cout<< "\t\tPress any number to continue..." << endl;
        cin >> key;
        system("cls");
    loop:
        cout << "\n   ->Press '1' To add Record:" << endl;
        cout << "   ->Press '2' To Display Record:" << endl;
        cout << "   ->Press '3' To Search Record:" << endl;
        cout << "   ->Press '4' To Modify Record:" << endl;
        cout << "   ->Press '5' To Delete Record:" << endl;
        cout << "   ->Press '6' To count all Record:" << endl;
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            cout<<"\n\t====================================================== \t\t\t "<<endl;
            cout<<"\t==========  Insert the information of student  =========\t\t\t "<<endl;
            cout<<"\t========================================================\t\t\t "<<endl<<endl;
            cout<< "Enter the name of the student : ";
            cin >> name;
            cout << endl<< "Enter the section : ";
            cin >> sec;
            cout << endl<< "Enter the cgpa of Student : ";
            cin >> cgpa;
            cout << endl<< "Enter the ID number : ";
            cin >> id;
            l.insertnode(name, sec, cgpa, id);
            goto loop;
            break;
        case 2:
            l.display();
            goto loop;
            break;
        case 3:
            l.search();
            goto loop;
            break;
        case 4:
            l.update();
            goto loop;
            l.deletee();
            goto loop;
            break;
        case 5:
            l.deletee();
            goto loop;
            break;
        case 6:
            l.sum();
            goto loop;
            break;
        default:
            cout << "\n\n==========  You enter wrong key... !!!  ========="<<endl;goto loop;
        }
    }

