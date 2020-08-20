/*
Project: Dual Clock
File: clock_functs.h (function interface)
Desc: provides the function and variable definitions
      for the program.

Programmer: Ryan Sanders
Date: 7-13-2020


*/


//variables for the clock, each are passed by refrence
//unsigned to save a few bytes of memory
 int hour, minute, second;

void displayMenu();

void displayClocks(int& hour, int& minute, int& second);

//update function definitions
void addMinute(int& minute , int& hour);

void addHour(int& hour);

void addSecond(int& second, int& minute, int& hour);



//Our version of a constructor
void initilzeTime(int& hour, int& minute, int& second);


void programLoop();