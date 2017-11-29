//
//  main.cpp
//  project3
//
//  Created by Jeffrey Ding on 10/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool hasCorrectSyntax(string song);                                     //function to check if song has correct syntax
int encodeSong(string song, string& instructions, int& badBeat);        //function to translate song
char encodeNote(int octave, char noteLetter, char accidentalSign);      //function to translate notes

int main()
{
    string t;
    string instructions;
    int badBeat;
    for (;;)
    {
        instructions = "";
        cout << "Enter song: ";
        getline(cin, t);
        if (t == "quit")
            break;
        cout << "hasCorrectSyntax returns ";
        if (hasCorrectSyntax(t))
        {
            cout << "true" << endl;
            cout << encodeSong(t, instructions, badBeat) << endl;
            cout << instructions << endl;
        }
        else
        {
            cout << "false" << endl;
            cout << encodeSong(t, instructions, badBeat) << endl;
        }
    }
}
//function to check if song has correct syntax
bool hasCorrectSyntax(string song)  //takes in a song string
{
    for (int x = 0; x != song.size(); x++)  //loops through entire song string, unless the song is ""
    {
        switch (song[x])    //switch case for current character
        {
            case '/':   //if the character is a beat ending, go to next iteration
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':   //if the character is A-G, check next character
                switch (song[x+1])  //switch case for next character
                {
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case '/':   //if the character is A-G or beat ending, go to next iteration
                        break;
                    case '#':
                    case 'b':   //if the character is an accidental, check next character
                        switch (song[x+2])  //switch case for the next character
                        {
                            case 'A':
                            case 'B':
                            case 'C':
                            case 'D':
                            case 'E':
                            case 'F':
                            case 'G':
                            case '/':   //if the character is A-G or beat ending, go to next iteration
                                x++;    //add one to x so it the next iteration checks for a note
                                break;
                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                            case '8':
                            case '9':   //if the character is a digit, check next character
                                switch (song[x+3])  //switch case for the next character
                                {
                                    case 'A':
                                    case 'B':
                                    case 'C':
                                    case 'D':
                                    case 'E':
                                    case 'F':
                                    case 'G':
                                    case '/':   //if the character is A-G or beat ending, go to next iteration
                                        x += 2; //add two to x so the next iteration checks for a note
                                        break;
                                    default:            //if anything else, the song string is syntaxically incorrect
                                        return false;   //return false
                                }
                                break;
                            default:            //if anything else, the song string is syntaxically incorrect
                                return false;   //return false
                        }
                        break;
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':   //if the character is a digit, check next character
                        switch (song[x+2])  //switch case for the next character
                        {
                            case 'A':
                            case 'B':
                            case 'C':
                            case 'D':
                            case 'E':
                            case 'F':
                            case 'G':
                            case '/':   //if the character is A-G or beat ending, go to next iteration
                                x++;    //add one to x so the next iteration checks for a note
                                break;
                            default:            //if anything else, the song string is syntaxically incorrect
                                return false;   //return false;
                        }
                        break;
                    default:            //if anything else, the song string is syntaxically incorrect
                        return false;   //return false;
                }
                break;
            default:            //if anything else, the song string is syntaxically incorrect
                return false;   //return false
        }
    }
    return true;    //if the string passes all the tests and doesn't return false, return true
    //note if the song string is of length 0, the for loop is skipped and the function returns true
}
//function that translates a song string into instructions for ButtonBass software
int encodeSong(string song, string& instructions, int& badBeat) //takes in a song string and reference variables that can be modified
{
    if(hasCorrectSyntax(song))  //if the song string has correct syntax
    {
        string tempSong = "";   //create a temporary song string that's empty
        bool sameChord = false; //create a boolean that checks if a beat has multiple notes
        int currentBeat = 1;    //create a integer that tracks the current beat of the song string
        for (int x = 0; x != song.size(); x++)  //loops through the song string
        {
            int octave = 4;                 //default octave
            char noteLetter = ' ';          //default note, which is a blank space
            char accidentalSign = ' ';      //default accidental, which is a blank space
            if (isalpha(song[x]))           //if the current note is an alphabet letter
            {
                noteLetter = song[x];       //set noteLetter to the current character
                if (isdigit(song[x+1]))     //if the next character is a digit
                {
                    octave = song[x+1] - 48;    //subtracts 48 from the ASCII value because digits from 0-9 are 48-57
                    x++;                        //and sets the octave to the character digit and add one to x in order to move to next character
                }
                else if (song[x+1] == '#' || song[x+1] == 'b')  //else if the next character is an accidental
                {
                    accidentalSign = song[x+1];     //set accidentalSign to the accidental character
                    x++;                            //add one to x in order to move to the next character
                    if (isdigit(song[x+1]))         //if the next character is a digit
                    {
                        octave = song[x+1] - 48;    //subtracts 48 from the ASCII value because digits from 0-9 are 48-57
                        x++;                        //and sets the octave to the character digit and add one to x in order to move to next character
                    }
                }
                if (isalpha(song[x+1]) && !sameChord)   //if the next character is an alphabet letter and sameChord isn't true
                {
                    sameChord = true;   //set sameChord to true
                    tempSong += '[';    //add '[' to the tempSong string to start a chord
                }
            }
            else    //else the current character is a beat ending
            {
                currentBeat++;  //thus add one to currentBeat to move to the next beat
                if(sameChord)   //if sameChord is true
                {
                    tempSong += ']';    //add ']' to the tempSong string to end the chord
                    sameChord = false;  //set sameChord to false
                }
                if(song[x+1] == '/')    //if the next character is also a beat ending
                {
                    tempSong += ' ';    //add a space to tempSong string
                }
                continue;               //move on to next iteration of the loop
            }
            if (encodeNote(octave, noteLetter, accidentalSign) == ' ')  //if the encoded note created is a space then the song is unplayable
            {
                badBeat = currentBeat;  //set badBeat to currentBeat
                return 2;               //return 2
            }
            tempSong += encodeNote(octave, noteLetter, accidentalSign); //if everything passes, add the encoded note to tempSong string
        }
        instructions = tempSong;    //if all characters go through with no errors, set instructions to the tempSong string
        return 0;                   //return 0
    }
    else            //else if the song string doesn't have correct syntax, it isn't a song string
    {
        return 1;   //return 1
    }
}

/*
*************************************
  encodeNote
*************************************

 Given an octave number, a note letter, and an accidental sign, return
 the character that the indicated note is encoded as if it is playable.
 Return a space character if it is not playable.

 First parameter:   the octave number (the integer 4 is the number of the
                    octave that starts with middle C, for example).
 Second parameter:  an upper case note letter, 'A' through 'G'
 Third parameter:   '#', 'b', or ' ' (meaning no accidental sign)

 Examples:  encodeNote(4, 'A', ' ') returns 'Q'
            encodeNote(4, 'A', '#') returns '%'
            encodeNote(4, 'H', ' ') returns ' '
 */

char encodeNote(int octave, char noteLetter, char accidentalSign)
{
    // This check is here solely to report a common CS 31 student error.
    if (octave > 9)
    {
        cerr << "********** encodeNote was called with first argument = "
        << octave << endl;
    }

    // Convert Cb, C, C#/Db, D, D#/Eb, ..., B, B#
    //      to -1, 0,   1,   2,   3, ...,  11, 12

    int note;
    switch (noteLetter)
    {
        case 'C':  note =  0; break;
        case 'D':  note =  2; break;
        case 'E':  note =  4; break;
        case 'F':  note =  5; break;
        case 'G':  note =  7; break;
        case 'A':  note =  9; break;
        case 'B':  note = 11; break;
        default:   return ' ';
    }
    switch (accidentalSign)
    {
        case '#':  note++; break;
        case 'b':  note--; break;
        case ' ':  break;
        default:   return ' ';
    }

    // Convert ..., A#1, B1, C2, C#2, D2, ... to
    //         ..., -2,  -1, 0,   1,  2, ...

    int sequenceNumber = 12 * (octave - 2) + note;

    string keymap = "Z1X2CV3B4N5M,6.7/A8S9D0FG!H@JK#L$Q%WE^R&TY*U(I)OP";
    if (sequenceNumber < 0  ||  sequenceNumber >= keymap.size())
        return ' ';
    return keymap[sequenceNumber];
}

