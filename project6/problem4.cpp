//
//  problem4
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

int* maxwell(int* a, int* b)    //returns pointer that points to the greater dereference value
{
    if (*a > *b)
        return a;
    else
        return b;
}

void swap1(int* a, int* b)  //swaps the addresses of the values but doesn't have an effect on the output
{
    int* temp = a;
    a = b;
    b = temp;
}

void swap2(int* a, int* b)  //actually swaps the values the pointers are pointing to
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int array[6] = { 5, 3, 4, 17, 22, 19 }; //initiliazes an array of ints size 6
    
    int* ptr = maxwell(array, &array[2]);   //initiliazes a pointer that points to &array[0]
    *ptr = -1;  //sets the value at &array[0] to -1
    ptr += 2;   //moves the pointer to &array[2]
    ptr[1] = 9; //sets the value of &array[3] to 9
    *(array+1) = 79;    //sets the value of &array[1] to 79
    
    cout << &array[5] - ptr << endl;    //prints the difference of &array[5] and &array[2], which is 3 because the address locations of an array are sequential
    
    swap1(&array[0], &array[1]);    //swaps the addresses of &array[0] and &array[1]
    swap2(array, &array[2]);        //swaps the values of &array[0] and &array[2]

    for (int i = 0; i < 6; i++)
        cout << array[i] << endl;    //prints out the each value of the array, which is now: 4, 79, -1, 9, 22, 19
}
