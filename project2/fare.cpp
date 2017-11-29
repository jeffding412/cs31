//
//  fare.cpp
//  fare
//
//  Created by Jeffrey Ding on 10/13/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    //input series
    cout << "Age of rider: ";                       //asks the user for age input
    int riderAge;
    cin >> riderAge;
    cin.ignore(10000, '\n');                        //consumes and discards all characters up to the new line so we can take string input
    cout << "Student? (y/n): ";                     //asks user for student input
    string student;
    getline(cin, student);                          // read a sequence of characters up to and including the next newline, and stores that sequence (without the newline) in a string variable
    cout << "Destination: ";                        //asks user for destination input
    string destination;
    getline(cin, destination);                      // read a sequence of characters up to and including the next newline, and store that sequence (without the newline) in a string variable
    cout << "Number of zone boundaries crossed: ";  //asks user for number of boundaries crossed input
    int zoneCrossed;
    cin >> zoneCrossed;
    //calculates fare price
    double fare = 1.35 + 0.55*zoneCrossed;                      //standard fare
    if (riderAge >= 65)                                         //fare for seniors
    {
        fare = 0.55 + 0.25 * zoneCrossed;                       //standard senior fare
        if (zoneCrossed == 0)                                   //senior fare with no zone crossing
            fare = 0.45;
        else if (student == "y" && zoneCrossed == 1)            //senior student fare discount
            fare = 0.65;
    }
    else if ((riderAge < 18 || student == "y") && zoneCrossed <= 1)      //minor and student discount
        fare = 0.65;
    
    cout.setf(ios::fixed);      //makes cout print floats with a fixed number of decimals
    cout.precision(2);          //in this case, it prints two decimal places
    
    cout << "---" << endl;      //print three hyphens
    //error messages
    if (riderAge < 0)
        cout << "The age must not be negative" << endl;                                     //if age input is negative, prints error
    else if (student != "y" && student != "n")
        cout << "You must enter y or n" << endl;                                            //if student input isn't "y" or "n", prints error
    else if (destination == "")
        cout << "You must enter a destination" << endl;                                     //if destination input is empty, prints error
    else if (zoneCrossed < 0)
        cout << "The number of zone boundaries crossed must not be negative" << endl;       //if number of boundaries crossed is negative, prints error
    else
        cout << "The fare to " << destination << " is $" << fare << endl;                   //if no erros, prints the fare price to destination
}
