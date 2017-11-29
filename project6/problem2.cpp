//
//  problem2
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    double* cat;
    double mouse[5];
    cat = mouse + 4;
    *cat = 25;
    *(mouse + 3) = 42;
    cat -= 3;
    cat[1] = 54;
    cat[0] = 27;
    bool b = (*cat == *(cat + 1));
    bool d = (cat == &mouse[0]);
}
