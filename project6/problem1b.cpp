//
//  problem1b
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

void findMax(int arr[], int n, int* &pToMax)
{
    if (n <= 0)
        return;      // no items, no maximum!
    
    pToMax = arr;
    
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *pToMax)
            pToMax = arr + i;
    }
}

int main()
{
    int nums[4] = { 5, 3, 15, 6 };
    int* ptr;
    
    findMax(nums, 4, ptr);
    cout << "The maximum is at address " << ptr << endl;
    cout << "It's at position " << ptr - nums << endl;
    cout << "Its value is " << *ptr << endl;
}
