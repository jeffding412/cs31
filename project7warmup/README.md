# cs31project7warmup
To help ease you into the world of classes you'll need for Project 7, we've designed these warmup exercises. (You will not turn in any of the code you write because of these warmups.)

Did you have a Tamagotchi or Gigapet when you were young? Here's your chance to implement a very simple one. This program compiles and runs, but does not produce the output it should, because the implementations of the member functions are incomplete or incorrect. Fix them so that the program produces the desired output.

The places to make a change are denoted by TODO comments. You must make no changes whatsoever to the reportStatus, careFor, or main functions.

There are a few features used here we haven't talked about yet, but Chapter 6 discusses them, and we'll talk about them in class Monday.
After you get everything working, try the each of the following experiments to test your understanding of some of concepts:

Try declaring the health member function private instead of public, and make sure you understand the resulting compilation error.
Comment out the entire implementation of Pet::eat, all the way from the void Pet::eat(int amt) to its close curly brace. Make sure you understand the resulting build error.
In main, try replacing myPets[0] = new Pet("Fluffy", 2); with myPets[0] = new Pet("Fluffy"); or myPets[0] = new Pet;, and make sure you understand the resulting compilation error.
Try removing the const from the implementation, but not the declaration of the alive member function. Notice the compilation error.
Try removing the const from both the declaration and the implementation of the alive member function. Make sure you understand why the use of that function doesn't compile in reportStatus, but does compile in careFor and main.
The program

The desired output

Here is the output we would like the program to produce:

======= Day 1
You fed Fluffy
Fluffy has health level 2
You fed Frisky
Frisky has health level 4
======= Day 2
You fed Fluffy
Fluffy has health level 2
You fed Frisky
Frisky has health level 4
======= Day 3
You forgot to feed Fluffy
Fluffy has health level 1
You forgot to feed Frisky
Frisky has health level 3
======= Day 4
You fed Fluffy
Fluffy has health level 1
You fed Frisky
Frisky has health level 3
======= Day 5
You fed Fluffy
Fluffy has health level 1
You fed Frisky
Frisky has health level 3
======= Day 6
You forgot to feed Fluffy
Fluffy has health level 0, so has died
You forgot to feed Frisky
Frisky has health level 2
======= Day 7
Fluffy is still dead
You fed Frisky
Frisky has health level 2
======= Day 8
Fluffy is still dead
You fed Frisky
Frisky has health level 2
======= Day 9
Fluffy is still dead
You forgot to feed Frisky
Frisky has health level 1
=======
Animal Control has come to rescue Frisky
