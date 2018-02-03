/*@file Missile_Command.cpp
*@author Ethan Sayles
*@date April, 29 2016
*@purpose read position, velocity, and acceleration data from a file, and determine if two objects will collide
*
* Helped Zach Whitaker, Matt Reed and Micah Zik with some parts of their code.
* DECIDED TO LOOP THE FILENAME ENTERING RATHER THAN QUITTING THE PROGRAM
*/

#include <iostream>
#include <assert.h>
#include<fstream>
#include<stdlib.h>
#include <iomanip>
#include <windows.h>   //used for the Sleep() function which I used to delay the cout some.

using namespace std;

//function prototypes
double position(double x_0,double V_0, double a, double t);
void test_position();

int main() {
    //Variable declaration
    const int SIZE = 14;                   //size of the array
    double file_data[SIZE] = {};           //array to store the data from the files
    ifstream infile;                       //file pointer
    string user_file = "";                 //string to store the file name
    string line = "";                      //string to store the line data from the files
    double position_x_1 = 0;               //the x position of object 1
    double position_x_2 = 0;               //the x position of object 2
    double position_y_1 = 0;               //the y position of object 1
    double position_y_2 = 0;               //the y position of object 2

    //run unit-test
    test_position();
    cout << "Identification verified. Security clearances passed." << endl;
    Sleep(1000);
    cout << "Preparing missiles for launch." << endl;
    Sleep(1000);

    //prompt the user for the file name and store the file's data in file_data, loop if invalid input
    while(true) {
        cout << "Enter launch-code (filename): ";
        getline(cin, user_file);
        infile.open(user_file);
        if (infile.is_open()) {
            for (int i = 0; i < SIZE; i++) {
                getline(infile, line);
                file_data[i] = atof(line.c_str());
            } //end for loop
            Sleep(1);
            infile.close();
            break;
        } //end if statement
        else {
            cout << "Error, code invalid" << endl;
            Sleep(1000);
        } //end else statement
    }

    cout << "Launch code verified" << endl;
    Sleep(1000);
    cout << "Launching missiles in t-minus:" << endl;
    Sleep(1000);
    cout << "----3----" << endl;
    Sleep(1000);
    cout << "----2----" << endl;
    Sleep(1000);
    cout << "----1----" << endl;
    Sleep(1000);
    cout << "----Missiles Launched!----" << endl;
    Sleep(1000);

    //print the positions and times in a table, stopping once there is a collision
    cout << "      Time         Missile 1       Missile 2" << endl;
    for (int i = 0; i < file_data[0]; i++){
        position_x_1 = position(file_data[2],file_data[3],file_data[4],i);
        position_x_2 = position(file_data[5],file_data[6],file_data[7],i);
        position_y_1 = position(file_data[8],file_data[9],file_data[10],i);
        position_y_2 = position(file_data[11],file_data[12],file_data[13],i);
        cout << setw(10) << i << setw(10) << "(" << position_x_1 << ", " << position_y_1 << ")"
        << setw(10) << "(" << position_x_2 << ", " << position_y_2 << ")" << endl;
        Sleep(500);
        if(abs(position_x_1 - position_y_2) <= file_data[1] && abs(position_y_1 - position_y_2) <= file_data[1]){
            cout << "It's a hit!  Collision occurred at time " << i << " seconds." << endl;
            break;
        } //end if statement
        if (i == file_data[0] - 1){
            cout << "Missiles never collided in " << i+1 << " seconds.";
        } //end if statement
    } //end for statement
    return 0;
} //end main

/** Gives the final position of an object
* @param X_0 the initial position
* @param V_0 the initial velocity
* @param a the acceleration
* @param t the change in time
* @return final_position the final position
*/
double position(double X_0,double V_0, double a, double t){
    double final_position = X_0 + V_0*t + .5*a*t*t;   //calculation for final position
    return final_position;
} //end position

/** Unit-Test for position()
* @param none
* @return void
*/
void test_position(){
    assert(position(0,-1,1,4) == 4);
    assert(position(8,0,-2,4) == -8);
    assert(position(-4,3,0,5) == 11);
    assert(position(3,7,8,0) == 3);
    assert(position(12,23,-4,10) == 42);
}


