// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "Header.h"

int main()
{	
	Date dd, d3;
	int y=0, m=0 , d=0;
	std::cin >> d3;
	Date d2{ 2020, Month::apr, 9 };
    std::cout << "Hello User! Please enter additional years, months, days to default 2000.01.01\n";
	std::cin >> y;
	std::cin >> m;
	std::cin >> d;
	dd.Date::add_day(d);
	dd.Date::add_month(m);
	dd.Date::add_year(y);	
	std::cout << dd;
	std::cout << d2;
	std::cout << d3;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
