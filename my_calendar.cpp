// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "Header.h"

int main()
{	
	Date d{ 2021, Month(4), 22 };
	std::cout << d <<'\n';
	std::vector<Course>courselist;	
	std::string cn;
    std::cout << "Hello User! Please enter name of course\n";	
	std::cin >> cn;
	Course c{ cn };
	c.add_deadline();
	std::cout << "Hello User! now we test the printing list\n";
	c.duelist();
/*	std::ofstream save_c;
	save_c.open("input2.txt");
	save_c.write((char*)&c, sizeof(c));

	std::ifstream open_c;
	open_c.open("input.txt");
	Course x2;
	open_c.read((char*)&x2, sizeof(x2));
	x2.duelist();*/
	
	return 0;
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
