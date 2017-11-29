//
//  array.cpp
//  project4
//
//  Created by Jeffrey Ding on 10/31/17.
//  Copyright © 2017 Jeffrey Ding. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value);
int lookup(const string a[], int n, string target);
int positionOfMax(const string a[], int n);
int rotateLeft(string a[], int n, int pos);
int countRuns(const string a[], int n);
int flip(string a[], int n);
int differ(const string a1[], int n1, const string a2[], int n2);
int subsequence(const string a1[], int n1, const string a2[], int n2);
int lookupAny(const string a1[], int n1, const string a2[], int n2);
int split(string a[], int n, string splitter);

int main()
{
    string h[7] = { "selina", "reed", "diana", "tony", "", "logan", "peter" };
    assert(lookup(h, 7, "logan") == 5);
    assert(lookup(h, 7, "diana") == 2);
    assert(lookup(h, 2, "diana") == -1);
    assert(positionOfMax(h, 7) == 3);
    
    string g[4] = { "selina", "reed", "peter", "sue" };
    assert(differ(h, 4, g, 4) == 2);
    assert(appendToAll(g, 4, "?") == 4 && g[0] == "selina?" && g[3] == "sue?");
    assert(rotateLeft(g, 4, 1) == 1 && g[1] == "peter?" && g[3] == "reed?");
    
    string e[4] = { "diana", "tony", "", "logan" };
    assert(subsequence(h, 7, e, 4) == 2);
    
    string d[5] = { "reed", "reed", "reed", "tony", "tony" };
    assert(countRuns(d, 5) == 2);
    
    string f[3] = { "peter", "diana", "steve" };
    assert(lookupAny(h, 7, f, 3) == 2);
    assert(flip(f, 3) == 3 && f[0] == "steve" && f[2] == "peter");
    
    assert(split(h, 7, "peter") == 3);
    string a[1] = { "" };
    
    cout << subsequence(f, 3, a, 0) << endl;
    cout << "All tests succeeded" << endl;
}

//append value to the end of each of the n elements of the array and return n
//return -1 if n is n3egative
int appendToAll(string a[], int n, string value)    //takes in array of strings, integer n, and string value
{
    if (n < 0)                        //if n is negative
        return -1;                  //return -1
    
    for (int x = 0; x < n; x++)     //iterate through the array up to the nth element of the array
        a[x] += value;              //append value to the string element
    
    return n;
}

//return the position of a string in the array that is equal to target
//if there is more than one such string, return the smallest position number of such a matching string
//return −1 if there is no such string.
int lookup(const string a[], int n, string target)  //takes in array of strings, integer n, and string target
{
    for (int x = 0; x < n; x++)     //iterate through the array up to the nth element of the array
        if (a[x] == target)         //if target is found
            return x;
    
    return -1;                      //if target not found, return -1
}
//return the position of a string in the array such that that string is >= every string in the array
//if there is more than one such string, return the smallest position in the array of such a string
//return −1 if the array has no elements
int positionOfMax(const string a[], int n)  //takes in array of strings and an integer n
{
    if (n <= 0)                     //if n is negative or empty
        return -1;
    
    string maxString = "";          //sets first string as an empty string
    int maxStringIndex = 0;         //sets the maxStringIndex to -1 in case no strings in array
    
    for (int x = 0; x < n; x++)     //iterate through the array up to the nth element of the array
        if (a[x] > maxString)       //if the string is greater than the maxString
        {
            maxStringIndex = x;     //set the maxStringIndex to the current index
            maxString = a[x];       //set the new maxString to the new element
        }
    
    return maxStringIndex;
}

//eliminate the item at position pos by copying all elements after it one place to the left
//put the item that was thus eliminated into the last position of the array
//return the original position of the item that was moved to the end
int rotateLeft(string a[], int n, int pos)  //takes in array of strings, integer n, and integer pos
{
    if (n < 0 || pos >= n || pos < 0)   //if n or p is negative, or pos is greater than n, if would cause undefined behavior
        return -1;                      //if so, return -1
    
    string temp = a[pos];               //set a temp string to hold the element at position pos
    
    for (int x = pos; x < n-1; x++)     //iterate through the array from the element at pos up to the second to last element of the array
        a[x] = a[x+1];                  //set the element at the current position to the next element
    
    a[n-1] = temp;                      //set the last element to the temp string
    
    return pos;
}

//return the number of sequences of one or more consecutive identical items in a
int countRuns(const string a[], int n)  //takes in array of strings and an integer n
{
    if (n < 0)                      //if n is negative
        return -1;                  //return -1
    else if (n == 0)                //else if n is 0
        return 0;                   //return 0
    
    int runCount = 1;               //runCount used to track number of consecutive identical items
    string repeat = a[0];           //repeat string used to hold the last string
    
    for (int x = 1; x < n; x++)     //iterate through the array from the second element to the nth element
    {
        if (repeat == a[x])         //if the current element is the same as the last element
            continue;               //go to next iteration
        
        runCount++;                 //add one to runCount
        repeat = a[x];              //set repeat to the current element
    }
    
    return runCount;
}

//return the position of the first corresponding elements of a1 and a2 that are not equal
//n1 is the number of interesting elements in a1, and n2 is the number of interesting elements in a2
//if the arrays are equal up to the point where one or both runs out, return whichever value of n1 and n2 is less than or equal to the other
int differ(const string a1[], int n1, const string a2[], int n2)    //takes in two arrays of strings and two integers
{
    if (n1 < 0 || n2 < 0 || (n1 == 0 && n2 == 0))   //if either n1 or n2 are negative or both are equal to 0
        return -1;                                  //return -1
    
    int totalRepetitions;                           //create int to determine how many elements to check
    
    if (n1 <= n2)                                   //store whichever integer input is less or either if they are equal into totalRepetitions
        totalRepetitions = n1;
    else
        totalRepetitions = n2;
    
    for (int x = 0; x < totalRepetitions; x++)      //iterate through the arrays to the totalRepetitionsth element
        if (a1[x] != a2[x])                         //if the compared elements are not equal
            return x;                               //return the index of the elements
    
    return totalRepetitions;                        //if reach here, then no differences, so return whichever n1 or n2 is less
}

//if all n2 elements of a2 appear in a1, consecutively and in the same order, then return the position in a1 where that subsequence begins
//if the subsequence appears more than once in a1, return the smallest such beginning position in the array
//return −1 if a1 does not contain a2 as a contiguous subsequence
int subsequence(const string a1[], int n1, const string a2[], int n2)   //takes in two arrays of strings and two integers
{
    if (n1 < 0 || n2 < 0 || n1 < n2)        //if either n1 or n2 are negative or n1 is less than n2, it will cause undefined behavior
        return -1;
    else if (n2 == 0 || (n1==0 && n2==0))
        return 0;
        
    int matched = 0;                        //set int to count number of matched in a row
    
    for (int x = 0; x < n1; x++)            //iterate through the a1 array to the n1th element
        for (int y = 0; y < n2; y++)        //iterate through the a2 array to the n2th element
        {
            if (a1[x] == a2[y])             //if both elements are the same
            {
                matched++;
                if (matched == n2)          //if the number of matched in a row is equal to the size of the second array
                    return x - matched + 1; //return the index of the first match on the first array
                x++;                        //adds one to x in order to compare the next elements
            }
            else
                matched = 0;                //if there is no match, set matched in a row back to 0
        }
    
    return -1;                              //if the for loop passes with no matches, return -1
}

//return the smallest position in a1 of an element that is equal to any of the elements in a2
//return −1 if no element of a1 is equal to any element of a2
int lookupAny(const string a1[], int n1, const string a2[], int n2) //takes in two arrays of strings and two integers
{
    if (n1 < 0 || n2 < 0)                   //if either n1 or n2 are negative, it will cause undefined behavior
        return -1;
    
    for (int x = 0; x < n1; x++)            //iterate through the first array to the n1th element
        if (lookup(a2, n2, a1[x]) != -1)    //if the element in the first array is ever found in the second array
            return x;                       //return the current index
    
    return -1;                              //if the for loop passes with no finds, return -1
}

//reverse the order of the elements of the array and return n
int flip(string a[], int n)         //takes in an array of strings and an integer
{
    if (n < 0)                      //if n is negative, it will cause undefined behavior
        return -1;
    
    string temp;                    //create a temp string variable to hold a string temporarily
    
    for (int x = 0; x < n/2; x++)   //iterate through half the affected values
    {
        temp = a[x];                //set the temp string to the current element
        a[x] = a[n - 1 - x];        //put the flipped element into the current element
        a[n - 1 - x] = temp;        //put the temp string into the flipped element
    }
    
    return n;
}

//rearrange the elements of the array so that all the elements whose value is < splitter come before all the other elements
//and all the elements whose value is > splitter come after all the other elements
//return the position of the first element that, after the rearrangement, is not < splitter, or n if there are no such elements.
int split(string a[], int n, string splitter)   //takes in an array of string, an integer, and a string splitter
{
    if (n < 0)                      //if n is negative, it will cause undefined behavior
        return -1;
    
    int sameIndex = 0;              //set an integer sameIndex to track where splitter would be if it was actually an element in the array
    
    for (int x = n-1; x >= 0; x--)  //iterating from the end of the array
        if (a[x] >= splitter)       //if the element is equal to or greater than splitter
            rotateLeft(a, n, x);    //call rotateLeft function to push current element to the end of the array and move everything to the left
        else
            sameIndex++;            //else, add one to sameIndex
    
    for (int x = 0; x < n; x++)     //iterate through the array
        if (a[x] == splitter)       //if the current element is the splitter string
        {
            string temp = a[x];     //set a temp string equal to the current element
            a[x] = a[sameIndex];    //set the current element to the element where the current element should be
            a[sameIndex] = temp;    //set the element in the replaced location to the temp string
            sameIndex++;            //add one to sameIndex because now it would be one to the right
        }
    
    for (int x = 0; x < n; x++)     //iterate through the array
        if (a[x] >= splitter)       //if the current element is greater than or equal to the splitter string
            return x;               //return the current index

    return n;                       //return n if the loop
}
