#include<iostream>
#include<iomanip> // needed for setfill and setw


struct Time { // initialize 3 struct variables, unit1, unit2 and unit3
	int hrs = 0;
	int min = 0;
	int sec = 0;
}unit1, unit2, unit3;

int time2sec(int hrs, int min, int sec);

void sec2time(int seconds_f, int& hrs_ptr, int& min_ptr, int& sec_ptr);

void time_difference(Time, Time); // passing entire structs by value to function

int main() {


	while (true) // input values into unit1
	{
		std::cout << "Input hours for time1: ";
		std::cin >> unit1.hrs;
		if (unit1.hrs >= 0 && unit1.hrs <= 23)
		{

			false;
			break;
		}
		std::cout << "Incorrect input, must be 0 - 23\n";
	}

	while (true)
	{
		std::cout << "Input minutes for time1: ";
		std::cin >> unit1.min;
		if (unit1.min >= 0 && unit1.min <= 59)
		{
			false;
			break;
		}
		std::cout << "Incorrect input, must be 0 - 59\n";
	}

	while (true)
	{
		std::cout << "Input seconds for time1: ";
		std::cin >> unit1.sec;
		if (unit1.sec >= 0 && unit1.sec <= 59)
		{
			false;
			break;
		}
		std::cout << "Incorrect input, must be 0 - 59\n";
	}





	while (true) // input values into unit2
	{
		std::cout << "\nInput hours for time2: ";
		std::cin >> unit2.hrs;
		if (unit2.hrs >= 0 && unit2.hrs <= 23)
		{
			false;
			break;
		}
		std::cout << "Incorrect input, must be 0 - 23\n";
	}

	while (true)
	{
		std::cout << "Input minutes for time2: ";
		std::cin >> unit2.min;
		if (unit2.min >= 0 && unit2.min <= 59)
		{
			false;
			break;
		}
		std::cout << "Incorrect input, must be 0 - 59\n";
	}

	while (true)
	{
		std::cout << "Input seconds for time2: ";
		std::cin >> unit2.sec;
		if (unit2.sec >= 0 && unit2.sec <= 59)
		{
			false;
			break;
		}
		std::cout << "Incorrect input, must be 0 - 59\n";
	}


	time_difference(unit1, unit2); // pass two different Times to function by value
												
	std::cout << "\nDifference in time between time1 and time2 is:\n" // prints out the difference
		<< std::setfill('0') << std::setw(2) << unit3.hrs << ":"
		<< std::setfill('0') << std::setw(2) << unit3.min << ":"
		<< std::setfill('0') << std::setw(2) << unit3.sec << std::endl;


	return 0;
}


void time_difference(Time unit1, Time unit2) { // changes the struct values with reference, so no return needed


	int time1_sec = time2sec(unit1.hrs, unit1.min, unit1.sec); // transform time into seconds
	int time2_sec = time2sec(unit2.hrs, unit2.min, unit2.sec); // transform time into seconds


	int difference_sec = (time2_sec - time1_sec); // calculates difference in seconds

	if (difference_sec < 0) // makes the difference always be positive
	{
		difference_sec = difference_sec * (-1);
	}


	sec2time(difference_sec, unit3.hrs, unit3.min, unit3.sec); // transforms the difference in seconds
																// back into readable time,
																// and inputs it into the struct variable unit3


}

void sec2time(int seconds_f, int& hrs_ptr, int& min_ptr, int& sec_ptr) // transforms seconds into
																		// readable time using reference
{

	hrs_ptr = seconds_f / 3600;
	min_ptr = (seconds_f % 3600) / 60;
	sec_ptr = ((seconds_f % 60) % 60);

}


int time2sec(int hrs, int min, int sec) { // transforms readable time into seconds

	sec += ((min * 60) + (hrs * 3600));

	return sec;
}