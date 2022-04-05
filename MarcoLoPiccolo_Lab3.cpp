// MarcoLoPiccolo_Lab3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>                //used for string data type
using namespace std;             //used for cout and cin statements

struct Date {                   //Structure Date is declared which has elements of all type int with day, month, and year
    int day;
    int month;
    int year;
};

struct Event {              //Structure Event declared with the first two elements being of string data type so that words
    string location;        //can be inputted without any issues
    string information;   
    Date eventDate;         //Final element uses the structure date for the data type so this element has the 3 elements of structure
};                          //Date within this one value

void inputDates(Date& theDate);    //Function Headers for all functions

void outputDates(Date& theDate);

void inputEventInfo(Event& theEvent);

void outputEventInfo(Event& theEvent);


int main()
{
    const int EVENTSNUMBER = 5;     //Constant integer declared for the array size with it staying at 5 for now
    Event userEvent[EVENTSNUMBER];   //Array of type Event declared with the eventsNumber size as the amount of elements in this array

    //For loop starts with an int i at 0 so that as it iterates it will stop right before the array size of 5
    for (int i = 0; i < EVENTSNUMBER; i++) {  //For loop used so that each element of the array has information inputted by user
        inputDates(userEvent[i].eventDate);   //Calls function to get the dates inputted
        inputEventInfo(userEvent[i]);         //Calls function to get the other information inputted

        outputDates(userEvent[i].eventDate);   //Calls these functions to output the information about the event that was inputted
        outputEventInfo(userEvent[i]);           //by the user
    }

    system("Pause");
    return 0;
}

//Function has the input parameter of class type date so that day, month, and year can be inputted into it
//It is pass by reference so that the values are saved into that class
//Main use of the function is to not output anything but allow the user to enter the day, month, and year of the event into the class
//then it is saved in that class
void inputDates(Date& theDate) {
    cout << "Enter Event Month: " << endl;           //Prompts user to enter a month and then it checks if it is between 1 and 12 
    cin >> theDate.month;                             //which represents the months of the year and the value is inputted using dotnotation
    while (theDate.month > 12 || theDate.month < 1) {
        cout << "Invalid Month, Please enter a valid month between 1 and 12" << endl;
        cin >> theDate.month;
    }

    cout << "Enter Event Day (Assume there are no leap years): " << endl;  //Prompts user to enter a day assuming no leap years
    cin >> theDate.day;                                                //uses dot notation to call that class value
    if (theDate.month == 1 || theDate.month == 3 || theDate.month == 5 || theDate.month == 7 || //The if statement checks to see if the 
        theDate.month == 8 || theDate.month == 10 || theDate.month == 12) {       //month is a 31 day month then it checks if the day is
        while (theDate.day > 31 || theDate.day < 1) {                             //valid
            cout << "Invalid Day for this month, please enter a day between 1 and 31" << endl;
            cin >> theDate.day;
        }
    }                                                               //Checks if the month is a 30 day month then checks to make sure
    else if (theDate.month == 4 || theDate.month == 6 || theDate.month == 9 || theDate.month == 11) {  //the day is valid
        while (theDate.day > 30 || theDate.day < 1) {
            cout << "Invalid Day for this month, please enter a day between 1 and 31" << endl;
            cin >> theDate.day;
        }
    }
    else {                                                    //Checks if the month is February which we are assuming is never a leap year
        while (theDate.day > 28 || theDate.day < 1) {     //Assume February is always 28 days
            cout << "Invalid Day for this month, please enter a day between 1 and 31" << endl;
            cin >> theDate.day;
        }
    }

    cout << "Enter Event Year: " << endl;        //Checks the year and only checks to make sure it is greater than 0
    cin >> theDate.year;
    while (theDate.year <= 0) {
        cout << "Invalid year, please enter a valid year that is greater than 0" << endl;
        cin >> theDate.year;
    }

    cout << endl;
}

//Function has one input parameter which is the value of class Date so that it can output the month, day, and year using dotnotation
//It is function void so that nothing is returned
void outputDates(Date& theDate) {
    cout << "The Event is happening on " << theDate.month << "/" << theDate.day << "/" << theDate.year;
}    //Tells the user the event is happening on the date sepearate by the / character

//Function has one input parameter of Event class type so that it can access the location and information string values in that class
//The function is void with pass by reference so the values of the location and information are saved in that class and nothing is returned
//Main point of the function is to get the user to enter the Event's location and the general information about it
void inputEventInfo(Event& theEvent) {
    cout << "Please Enter the event's location" << endl;  //Prompts user to enter the location
    getline(cin >> ws, theEvent.location);      //cin >> ws included so that the previous cin whitespace is negated and it goes to a newline
                                                //so that getline can be properly used to enter the string of the location info
    cout << "Please Enter the event's information" << endl;
    getline(cin, theEvent.information);         //A normal getline is used here as the previous cin >> ws already solves the problem
}                                               //with the cin from the last function and getline is used to allow for spaces to be 
                                                 //inputted by the user

//Function has one input parameter which is the value of class Event so that it can output the location and information using dotnotation
//It is function void so that nothing is returned
void outputEventInfo(Event& theEvent) {
    cout << " at " << theEvent.location << " for "  //Continues the message from previous output function so that it says where it is
        << theEvent.information << endl;            //and the information about the event
}