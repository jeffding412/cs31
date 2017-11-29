//
//  problem1d
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

// return true if two C strings are equal
bool strequal(const char* str1, const char* str2)
{
    while (*str1 != 0  &&  *str2 != 0)
    {
        if (*str1 != *str2)  // compare corresponding characters
            return false;
        str1++;            // advance to the next character
        str2++;
    }
    return *str1 == *str2;   // both ended at same time?
}


int main()
{
    char a[15] = "Zhou";
    char b[15] = "Zhu";
    
    if (strequal(a,b))
        cout << "They're the same person!\n";
}
