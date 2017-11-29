//
//  problem5
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

void removeS(char* msg)
{
    char* result = msg;
    for (;*msg != 0; msg++)
    {
        if (*msg == 'S' || *msg == 's') {
            continue;
        }
        else
        {
            *result = *msg;
            result++;
        }
    }
    *result = 0;
}

int main()
{
    char msg[50] = "She'll be a massless princess.";
    removeS(msg);
    cout << msg;  // prints   he'll be a male prince.
}
