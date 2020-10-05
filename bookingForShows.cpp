#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int checkName(string names[],int n,string name){
    for (int i = 0; i < n; i++)
    {
        if (name==names[i])
        {
            return 0;
        }
        
    }
    return 1;  
} 
int main()
{
    int discount = 0;
    int price = 100, totalTickets[4] = {50, 50, 50, 50}, male = 0, female = 0, age, hour, minutes, cardNumber, userInputBooking;
    int timeSlots[4] = {10, 12, 14, 16};
    int bookingPrice,bookingListCounter=0;
    int numberOfTickets, slot;
    string bookingName,bookingNameList[100];
    char start, gender;
    cout << "Do you wanna continue(y/n)???";
    cin >> start;
    while (start == 'y')
    {
        discount=0;
        cout << "Welcome to ticket counter " << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << "please enter your basic info " << endl;
        cout << "First name: ";
        cin >> bookingName;
        if(checkName(bookingNameList,bookingListCounter,bookingName)==0){
            cout<<"you already done booking u cant do now ";
            continue;
        }
        cout << "Gender(m/f): ";
        cin >> gender;
        cout << "Age in years : ";
        cin >> age;
        cout << "Please enter the hour in 24 hour system ";
        cin >> hour;
        cout << "please enter the minutes ";
        cin >> minutes;
        cout << "Please select a slot you wanna do booking in :" << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << "1: 10am-11am" << endl
             << "2: 12pm-1pm" << endl
             << "3: 2pm-3pm" << endl
             << "4: 4pm-5pm" << endl;
        cin >> slot;
        while (true)
        {
            if(timeSlots[slot-1]>hour)
            {
                if(timeSlots[slot-1]-hour==1 && 60-minutes<=10){
                    cout<<"You cant book book 10min before enter another slot: ";
                    cin>>slot;
                    continue;
                }
                break;
            }
            cout<<"Please select another slot you cant book to that slot now :";
            cin>>slot;
        }
        while (true)
        {
            if (totalTickets[slot - 1] > 0)
            {
                break;
            }
            cout << "Sorry this slot doesnt have any seats left please enter a different slot" << endl;
            cin >> slot;
        }

        cout << "Please enter the number of tickets you want book." << endl
             << "Warning: It should be less than or equal to 4" << endl;
        cin >> numberOfTickets;
        if (numberOfTickets > 4 || numberOfTickets < 1)
        {
            while (true)
            {
                if (numberOfTickets <= 4 && numberOfTickets >= 1)
                {
                    if (numberOfTickets == 4)
                    {
                        discount += 40;
                    }
                    break;
                }
                cout << "Invalid number of tickets booked" << endl
                     << "please enter a valid one :" << endl;
                cin >> numberOfTickets;
            }
        }
        while (true)
        {
            if (totalTickets[slot - 1] >= numberOfTickets)
            {
                break;
            }
            cout << "Sorry we dont have these many tickets left reduce number of tickets" << endl;
            cin >> numberOfTickets;
        }

        if (numberOfTickets > 1)
        {
            male = 0;
            female = 0;
        }
        if (numberOfTickets == 1 && male == 1)
        {
            cout << "sorry you cant book tickets cant book you after a single man " << endl;
            cout<<"do u wanna reset (y/n) ";
            cin>>start;
            continue;
        }
        if (numberOfTickets == 1 && female == 1)
        {
            cout << "sorry you cant book tickets because of company policy cant book u after a women" << endl;
            cout<<"do u wanna continue (y/n) ";
            cin>>start;
            continue;
        }
        if (numberOfTickets == 1 && gender == 'm')
        {
            male = 1;
            female = 0;
        }
        if (numberOfTickets == 1 && gender == 'f')
        {
            female = 1;
            male = 0;
        }
        totalTickets[slot - 1] -= numberOfTickets;
        cout << "Congrats Tickets booked" << endl
             << endl;
        bookingNameList[bookingListCounter]=bookingName;
        bookingListCounter++;
        string name[numberOfTickets];
        int ageOfBook[numberOfTickets];
        char genderOfBook[numberOfTickets];
        cout << "Enter the details of the people you want to book ticket for," << endl
             << "if you are also one of them please write your details once again " << endl
             << "Per tickets costs 100rs " << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        for (int i = 0; i < numberOfTickets; i++)
        {
            cout << "Deatils of person no " << i + 1 << endl
                 << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << "First name : ";
            cin >> name[i];
            cout << "Gender(m/f) : ";
            cin >> genderOfBook[i];
            cout << "Age :";
            cin >> ageOfBook[i];
            if (ageOfBook[i] > 70)
            {
                discount += 20;
                cout << "You have got a discount of 20rs for overage " << endl;
            }
            if (ageOfBook[i] < 3)
            {
                discount += 30;
                cout << "You have got a discount of 30rs for underage " << endl;
            }
        }
        bookingPrice = (numberOfTickets * price) - discount;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << "Now the Payment details :" << endl
             << "Your total bill : " << bookingPrice << endl
             << "Please enter card no. :";
        cin >> cardNumber;
        cout << "Please enter the total price again for us: ";
        cin >> userInputBooking;
        while (true)
        {
            if (userInputBooking == bookingPrice)
            {
                break;
            }
            cout << "Wrong value enter again ";
            cin >> userInputBooking;
        }

        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << "Congratsss!!!!!!! booking successfull" << endl
             << "Heres your ticket :" << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
             << endl;

        for (int i = 0; i < numberOfTickets; i++)
        {
            cout << name[i] << "\t" << ageOfBook[i] <<"\t"<<genderOfBook[i]<< endl;
        }

        cout << endl
             << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Do you wanna continue(y/n)???";
        cin >> start;
    }

    return 0;
}