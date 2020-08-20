/*
Project: Dual Clock
File: Clock_Project.cpp (main entry)
Desc: Displays a 12 hour and 24 hour clock which is updated each second
      until a key is pressed. Once a key is pressed, a menu appears that
      allows for manual update of the clocks.
Programmer: Ryan Sanders
Date: 7-13-2020
*/

#include <iostream>
#include <windows.h> //gives us to the operating systems's sleep and key press functions
#include "clock_functs.h" // access to the guts of our clock

using namespace std;
bool iskeypressed(unsigned timeout_ms = 0)
{
    return WaitForSingleObject(
        GetStdHandle(STD_INPUT_HANDLE),
        timeout_ms
    ) == WAIT_OBJECT_0;
}


void programLoop()
{
    //the clocks will display and update each second
    //until a key is pressed, then the menu will display
    while (!iskeypressed(1))
    {
        
        displayClocks(hour, minute, second);
        Sleep(1000); //sleep for 1000 miliseconds or 1 second
        addSecond(second, minute, hour);
        //clear the screen
        system("CLS");
    }
}

int main()
{
    //unsigned saves on memory, and even if they enter a negative number
    //the underflow will still be acceptable and trigger the default option
    unsigned int menuSelection=0;
    bool keepRunning = true;

    while (keepRunning) {
     
        programLoop();
        displayMenu();

        cout << "Please select an option:" << endl;
        cin >> menuSelection;
        

        switch (menuSelection)
        {
        case 1:
            addHour(hour);
            break;
        case 2:
            addMinute(minute, hour);
            break;
        case 3:
            addSecond(second, minute, hour);
            break;
        case 4:
            keepRunning = false;
            break;
        default:
            cout << "Invalid input" << endl;
            
        }
        
    }
}