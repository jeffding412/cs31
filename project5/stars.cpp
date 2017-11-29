//
//  stars.cpp
//  stars
//
//  Created by Jeffrey Ding on 11/14/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include "utilities.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const char WORDFILENAME[] = "/Users/jeffreyding/Desktop/Computer Science Projects/CS31/project5/project5/smallwords.txt";

int runOneRound(const char words[][7], int nWords, int wordnum);
bool legalProbe(const char probeword[], const char words[][7], int nWords);
int probing(const char probeword[], const char target[]);

int main()
{
    char w[9000][7];                            //declares an array of C strings
    int n = getWords(w, 9000, WORDFILENAME);    //declares an int that holds actual number of words in the array
    
    if (n < 1)                                  //if the array has no elements, print error message
    {
        cout << "No words were loaded, so I can't play the game." << endl;
        return 0;
    }
    
    cout << "How many rounds do you want to play? ";    //prompts user for number of rounds to play
    int numberOfRounds;
    cin >> numberOfRounds;
    cin.ignore(10000, '\n');
    
    if (numberOfRounds < 1)                             //if number of rounds entered it zero, print message and end program
    {
        cout << "The number of rounds must be positive." << endl;
        return 0;
    }
    
    double totalAttempts = 0;   //sets total attempts to 0
    int numberOfAttempts;       //declares an int that holds number of attempts of that round
    int maximum = INT8_MIN;      //creates a maximum value that is the smallest value possible
    int minimun = INT8_MAX;      //creates a minimum value that is the largest value possible
    
    for (int x = 0; x < numberOfRounds; x++)    //iterate through the number of rounds
    {
        cout << "\nRound " << x+1 << endl;        //outputs required dialog
        int randomNumber = randInt(0, n-1);
        
        cout << "The secret word is " << strlen(w[randomNumber]) << " letters long." << endl;
        
        numberOfAttempts = runOneRound(w, n, randomNumber);                 //stores number of attempts
        
        if (numberOfAttempts == 1)
            cout << "You got it in 1 try." << endl;
        else
            cout << "You got it in " << numberOfAttempts << " tries." << endl;
        
        if (numberOfAttempts > maximum)                                     //if number of attempts is greater than the maximum, set new maximum
            maximum = numberOfAttempts;
        if (numberOfAttempts < minimun)                                     //if number of attempt is less than the minimum, set new minimum
            minimun = numberOfAttempts;
        totalAttempts += numberOfAttempts;                                  //add number of attempts to total attempts
        
        cout.setf(ios::fixed);                                              //allows for two decimals output
        cout.precision(2);
        
        cout << "Average: " << totalAttempts/(x+1) << ", minimum: " << minimun << ", maximum: " << maximum << endl;
    }
}

int runOneRound(const char words[][7], int nWords, int wordnum) //function that takes in an array of C strings, the number of words in the array, and an int index
{
    if (nWords < 1 || wordnum < 0 || wordnum >= nWords) {       //return -1 error if the number of words in the array is not positive, or if the index of the target word is negative, or if the index of the the target word is not in the array
        return -1;
    }
    
    char probeWord[101];
    
    int attempts = 0;
    while (strcmp(words[wordnum], probeWord) != 0)          //while the target and probe array aren't the same
    {
        cout << "Probe word: ";                             //prompt user for a probe word
        cin.getline(probeWord, 101, '\n');
        
        if (strcmp(words[wordnum], probeWord) == 0)         //if the two arrays are the same, get out of the while loop
        {
            attempts++;
            break;
        }
        
        if (legalProbe(probeWord, words, nWords))           //if the probe word is legal
            attempts += probing(probeWord, words[wordnum]); //probe the word and add one to attempts
    }
    
    return attempts;    //when the target word is aquired, return number of attempts
}

int probing(const char probeWord[], const char target[])                //function that outputs intermediate
{
    bool samePosition[] = {false, false, false, false, false, false};   //boolean array to track if two characters are the same at the same position
    bool foundPlanet[] ={false, false, false, false, false, false};     //boolean array to track if a planet was found in the array
    int stars = 0;
    int planets = 0;
    
    for (int x = 0; target[x] != '\0'; x++) //loop through the target array
    {
        if (probeWord[x] == target[x])      //if the positions have the same character, set both boolean array values to true at the element
        {
            stars++;
            samePosition[x] = true;
            foundPlanet[x] = true;
        }
    }
    
    for (int x = 0; probeWord[x] != '\0'; x++)                  //loop through the probe array
    {
        if (samePosition[x])    //if the current element is a star, move on to next element
            continue;
        for (int y = 0; target[y] != '\0'; y++)                 //loop through the target array
            if (target[y] == probeWord[x] && !foundPlanet[y])   //if the target and probe elements are the same and the current element hasn't been found yet
            {
                planets++;
                foundPlanet[y] = true;                          //set the current element in the foundPlanet array to true, then move on to next element in the probe array
                break;
            }
    }
    
    cout << "Stars: " << stars << ", Planets: " << planets << endl;
    return 1;
}

bool legalProbe(const char probeWord[], const char words[][7], int nWords)      //function that returns boolean that takes in a probeword array, the words array, and an int of number of words
{
    if (strlen(probeWord) < 4 || strlen(probeWord) > 6)     //if the probeword is not 4-6 characters, print error message and return false
    {
        cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
        return false;
    }
    
    for (int x = 0; probeWord[x] != '\0'; x++)              //if the probeword contains non-lowercase characters, print error message and return false
    {
        if (!islower(probeWord[x]) || !isalpha(probeWord[x])) {
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            return false;
        }
    }
    
    for (int x = 0; x < nWords; x++)                        //if probeword is in the valid words array, return true
        if (strcmp(probeWord, words[x]) == 0)
            return true;
    
    cout << "I don't know that word." << endl;              //if it goes through the valid words array and doesn't exist, print error message and return false
    return false;
}
