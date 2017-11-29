//
//  problem1a
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int arr[3] = {5, 10, 15};
    int* ptr = arr;
    
    *ptr = 30;
    *(ptr + 1) = 20;
    *(ptr + 2) = 10;
    
    while (ptr <= (arr+2))
    {
        cout << *ptr << endl;
        ptr++;
    }
}
