/*
Project: Dual Clock
File: clock_functs.cpp (operating functions)
Desc: Provides the necessary logic needed to display and update the clock.
      All variables are passed by refrence from one function to another.
      self-contained classes would probably be better but hey, this is
      more creative and fun.

Programmer: Ryan Sanders
Date: 7-13-2020


*/

#include <iostream>
#include <iomanip>

using namespace std;


//Outputs the menu 
void displayMenu()
{
    cout << "........................................." << endl;
    cout << ".......Please chose an option............" << endl;
    cout << "...(1) Add an hour                    ..." << endl;
    cout << "...(2) Add a Minute                   ..." << endl;
    cout << "...(3) Add a second                   ..." << endl;
    cout << "...(4) Exit program                   ..." << endl;
    cout << "........................................." << endl;
}



//adds an our to our clock
void addHour(int& hour)
{
    if (hour < 24)
    {
        hour += 1;
    }
    else {
        hour = 0;
    }
   
} 

// adds a minute to the clock
void addMinute(int& minute, int& hour)
{
    if (minute != 59)
    {
        minute += 1;
    }
    else {
        minute = 0;
        addHour(hour);
    }
}

//adds a second to the clock
void addSecond(int& second ,int& minute, int& hour)
{
    if (second != 59)
    {
        second += 1;
    }
    else {
        second = 0;
        addMinute(minute, hour);
    }


}
//sets up the clock. Basically, our version of a constructor
void initilzeTime(int& hour, int& minute, int& second)
{
    hour = 0;
    minute = 0;
    second = 0;

}

//displays the actual clocks
//beccause the vars are passed by refrence, we need to include them all here
//second modifies minutes and minutes modify hours, we need to pass everything
//up. Each function strips off on parameter, almost like peeling an onion.
void displayClocks(int& hour, int& minute, int& second)
{
    cout << "Clocks running. Press any key to call edit menu." << endl;
    //lets set a few things up so we can display both clocks
    string suffix; // AM/PM for the 12 hour clock
    unsigned int hour_12; // we'll convert from 24hrs to 12hrs
    
    //Deternine if we need AM or PM for the 12hr format
    if (hour > 12)
    {
        hour_12 = hour - 12;
        suffix = "P M"; 
    }
    else {
        hour_12 = hour;
        suffix = "A M";
    }
    //output the clocks.
    cout << "********************\t\t\t********************" << endl;
    cout << "** 12 hour clock  **\t\t\t** 24 hour clock  **" << endl;
    //line for the 12 clock
    cout  << "**  " << setw(2) << setfill('0') << hour_12;
    cout << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << suffix;
    //line for the 24hr clock
    cout << "  **\t\t\t**  " << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" 
        << setw(2) << setfill('0') << second << " \t  **" << endl;
    cout << "********************\t\t\t********************" << endl;
}   


