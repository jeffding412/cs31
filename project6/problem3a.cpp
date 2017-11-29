//
//  problem3a
//  project6
//
//  Created by Jeffrey Ding on 11/21/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
using namespace std;

double mean(const double* scores, int numScores)
{
    const double* ptr = scores;
    double tot = 0;
    for (int x = 0; x < numScores; x++)
        tot += *(ptr + x);
    return tot/numScores;
}

int main()
{
    double scores[] = {100, 75, 87, 98, 63};
    double average = mean(scores, 5);
    cout << average << endl;
}
