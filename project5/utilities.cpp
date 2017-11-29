// utilities.cpp

#define _CRT_SECURE_NO_DEPRECATE

#include "utilities.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <random>
#include <utility>
using namespace std;

//*********************
//***  On a Windows system, if you provide a path for the wordfilename,
//***  use / in the string instead of \ (e.g., "Z:CS31/P5/mywordfile.txt").
//
//***  On a Mac, it's probably easiest to use the complete pathname to
//***  the words file, e.g. "/Users/yourUsername/words.txt" or
//***  "/Users/yourUsername/CS31/P5/words.txt".
//
//***  On a SEASnet Linux server, if you put the words.txt file in the
//***  same directory as your .cpp file, you can use "words.txt" as the
//***  file name string.

int getWords(char words[][MAXWORDLEN+1], int maxWords, const char wordfilename[])
{
    ifstream wordfile(wordfilename);
    if ( ! wordfile)
    {
        cout << "Cannot open " << wordfilename << "!" << endl;
        return -1;
    }
    const int MAXFILELINELEN = 10000;
    char line[MAXFILELINELEN];
    int numWords = 0;
    while (wordfile.getline(line, MAXFILELINELEN))
    {
        // Store only words with of the right number of lower case letters
        
        int k;
        for (k = 0; islower(line[k]); k++)
            ;
        
        // The following two lines fix a potential issue for non-Windows
        // users and are harmless for Windows users.
        
        if (line[k] == '\r')
            line[k] = '\0';
        
        if (numWords == maxWords)
        {
            cout << "Using only the first " << numWords << " words from "
            << wordfilename << "." << endl;
            break;
        }
        
        if (line[k] == '\0'  &&  k >= MINWORDLEN  &&  k <= MAXWORDLEN)
        {
            strcpy(words[numWords], line);
            numWords++;
        }
    }
    return numWords;
}

// Return random int from min to max, inclusive
int randInt(int min, int max)
{
    if (max < min)
        swap(max, min);
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}
