#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void book();
void deletrecords();
void modify ();
void total_allotted();
void display();
int y=0,*ptr=&y;
struct rooms
{
    string user;
    string date;
};
int main()
{
    int x;

    while (1)
    {   cout << "***************** Hotel Managment System ******************* \n";
        display();
        cout<<" How can i serve your MS : choose number : ";
        cin >>x;
        if (x==1)
            {
                book();
                y++;
            }
        else if (x==2)
            {
                deletrecords();
                y--;
            }
        else if (x==3)
            modify();
        else if (x==4)
            total_allotted();
        else if (x==5)
            break;
        else cout << "Wrong number you choice : try again \n";

    }
    return 0;
}
void book ()
{
    rooms r;
    int counter=0;
    cout << "Enter user name please : ";
    cin>> r.user;
    ifstream name ("book.txt");
    string temp;
    while (name>>temp)
    {
        if (temp==r.user)
        {
            counter++;
            break;
        }
    }
    name.close();

    if (counter==1)
    {
        cout<<"This user already book a room \n";
    }
    else
    {
        ofstream name("book.txt");
        name<<r.user;
        cout <<"how long you will stay here : ";
        cin >> r.date;
        ofstream date ("date.txt");
        date<<r.date;
        date.close();
        cout<< "Thank you MS "<<r.user<<" Have a nice day \n";
    }
    name.close();
}
void deletrecords ()
{
    rooms r;
    cout<< "Enter your client name to delet : ";
    cin>>r.user;
    ifstream name ("book.txt");
    string temp;
    while (name>>temp)
    {
        if (temp==r.user)
        {
            continue;
        }
        else
        {
            ofstream name2 ("book2.txt");
            name2<<temp;
            name2.close();
        }
    }
    name.close();

    ifstream name2 ("book2.txt");

    while (name2>>temp)
    {
        ofstream name ("book.txt");
        name<<temp;

    }
    name.close();
    name2.close();
    cout << "user is deleted complete : \n";
}
void total_allotted()
{
    string temp;
    ifstream name ("book.txt");
    int counter=0,i,k=0;
    for (i=0;i<*ptr;i++)
    {
        name>>temp;
        counter++;
    }
    name.close();
    cout << "number allotted rooms = "<<counter<<endl;
}
void modify ()
{
    rooms r;
    ofstream name ("book.txt");
    deletrecords();
    cout<< "Enter your new record : ";
    cin >>r.user;
    name<<r.user;
    cout << "New modifyed was add completed : \n";
    name.close();
    cout << "now edit your date : please enter your last recorded date : ";
    cin >>r.date;
    ofstream date ("date.txt");
    date<<r.date;
    date.close();
}
void display()
{
    cout << " 1- book room : \n";
    cout << " 2- delete recorded : \n";
    cout << " 3- modify recorded : \n";
    cout << " 4- total allotted rooms : \n";
    cout << " 5 - exist program \n";
}
