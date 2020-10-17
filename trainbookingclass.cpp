#include<iostream>
#include<cstdio>
using namespace std;
class PersonalDetails{
    protected:
    string name;
    char gender;
    int age;
    public:
    PersonalDetails(){
        cout<<"Please Enter the name ";
        cin>>name;
        cout<<"Age ";
        cin>>age;
        cout<<"Gender(M/F) ";
        cin>>gender;
    }
};

class BookingDetails{
    protected:
    int adharCard;
    string source;
    string destination;
    public:
    BookingDetails(){
            cout<<"Enter the adhar card no : ";
            cin>>adharCard;
            cout<<"Enter the source : ";
            cin>>source;
            cout<<"Enter the destination ";
            cin>>destination;
    }
};

class Book:public PersonalDetails,public BookingDetails{
    protected:
        static int seatNo;
        int price;
        int choice;
    public:
        Book(){
            cout<<"Welcome to indian railways wat do u wanna do?? enter\n1. book\n2.update\n3.cancel\n";
            cin>>choice;
            switch (choice)
            {
            case 1:
                book();
                break;
            case 2:
                update();
                break;
            case 3:
                cancel();
                break;
            
            default:
                break;
            }
        }
        void againContructor(){
            cout<<"Welcome to indian railways wat do u wanna do?? enter\n1. book\n2.update\n3.cancel\n";
            cin>>choice;
            switch (choice)
            {
            case 1:
                book();
                break;
            case 2:
                update();
                break;
            case 3:
                cancel();
                break;
            
            default:
                break;
            }
        }

        void book(){
            seatNo++;
            cout<<"Booking confirmed!!!!"<<endl<<"Your seat no is "<<seatNo<<endl;
        }

        void update(){
            int choiceUpdate;
            cout<<"What do u wanna update \n1.name\n2.gender\n3.adharCard\n4.Age\n5.source\n6.destination"<<endl;
            cin>>choiceUpdate;
            switch (choiceUpdate)
            {
            case 1:
                cout<<"What name change you wanna do ?";
                cin>>name;
                break;
            case 2:
                cout<<"What gender change you wanna do(M/F) ?";
                cin>>gender;
                break;
            case 3:
                cout<<"What adharcard change you wanna do ?";
                cin>>adharCard;
                break;
            case 4:
                cout<<"What age change you wanna do ?";
                cin>>age;
                break;
            case 5:
                cout<<"What source change you wanna do ?";
                cin>>source;
                break;
            case 6:
                cout<<"What destination change you wanna do ?";
                cin>>destination;
                break;
            
            default:
                cout<<"invalid choice\n";
                break;
            }

            againContructor();
        }

        void cancel(){
            cout<<"Your ticket has been cancel \n";
            name='\0';
            gender='\0';
        }

        void show(){
            cout<<name<<"\t"<<gender<<"\t"<<seatNo<<endl;
        }

};

class RailwaysCounter{
    protected:
        int totalNoOfTickets;
        Book *b;
        static int pnr;
    public:
        RailwaysCounter(){
            cout<<"How many tickets you wanna book ";
            cin>>totalNoOfTickets;
            b=new Book[totalNoOfTickets];
            cout<<"---------------------------------------------\n";
            for (int i = 0; i < totalNoOfTickets; i++)
            {
                b[i].show();
            }
            cout<<"-----------------------------------------------\n";
            cout<<"Thank you for visiting\n";
        }
};

int RailwaysCounter::pnr;

int Book::seatNo;
int main(){
    RailwaysCounter r;
    return 0;
}