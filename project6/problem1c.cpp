//
//  problem1c
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

void computeCube(int n, int* ncubed)
{
    *ncubed = n * n * n;
}

int main()
{
    int x = 5;
    int* ptr = &x;
    computeCube(x, ptr);
    cout << "Five cubed is " << *ptr << endl;
}

