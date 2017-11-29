// Fare calculator

#include <iostream>
#include <string>
using namespace std;

int main()
{
      // Get and validate rider's age

    cout << "Age of rider: ";
    int age;
    cin >> age;
    cin.ignore(10000, '\n');
    if (age < 0)
    {
        cout << "---\nThe age must not be negative" << endl;
        return 1;
    }

      // Get and validate student status

    cout << "Student? (y/n): ";
    string student;
    getline(cin, student);
    if (student != "y"  &&  student != "n")
    {
        cout << "---\nYou must enter y or n" << endl;
        return 1;
    }

      // Get and validate destination

    cout << "Destination: ";
    string destination;
    getline(cin, destination);
    if (destination == "")
    {
        cout << "---\nYou must enter a destination" << endl;
        return 1;
    }

      // Get and validate number of zone boundaries crossed

    cout << "Number of zone boundaries crossed: ";
    int nZones;
    cin >> nZones;
    cin.ignore(10000, '\n');
    if (nZones < 0)
    {
        cout << "---\nThe number of zone boundaries crossed must not be negative"
	     << endl;
        return 1;
    }

      // Fare thresholds and rates

    const int ADULT_THRESHOLD_AGE  = 18;
    const int SENIOR_THRESHOLD_AGE = 65;
    const double BASE_FARE               = 1.35;
    const double PER_ZONE_RATE           = 0.55;
    const double SPECIAL_SHORT_TRIP_FARE = 0.65;
    const double SENIOR_BASE_FARE        = 0.55;
    const double SENIOR_PER_ZONE_RATE    = 0.25;
    const double SENIOR_SHORT_TRIP_FARE  = 0.45;

      // Compute fare

    double fare;

    if (age < SENIOR_THRESHOLD_AGE)	// regular fare
	fare = BASE_FARE + nZones * PER_ZONE_RATE;

    else if (nZones == 0)		// senior short trip
	fare = SENIOR_SHORT_TRIP_FARE;

    else				// senior normal trip
	fare = SENIOR_BASE_FARE + nZones * SENIOR_PER_ZONE_RATE;

      // Adjust fare for minor and student short trips

    if (nZones <= 1  &&  (age < ADULT_THRESHOLD_AGE  ||  student == "y"))
    {
	  // Give discount if it's better than what we've computed so far

	if (fare > SPECIAL_SHORT_TRIP_FARE)
	    fare = SPECIAL_SHORT_TRIP_FARE;
    }

      // Print fare

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "---\nThe fare to " << destination << " is $" << fare << endl;
}
