// Calendar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "Header.h"

int main()
{	
	std::string input;
	std::string cn;
	std::vector<Course>courselist;
	while (true) {
		print_menu();
		std::cin >> input;
		switch (command(input)) {
			case Input_T::error: std::cout << "incorrect output, type quit and hit enter to leave program.\n";
			break;
			case Input_T::load: std::cout << "not implemented yet.\n";
			break;
			case Input_T::save: std::cout << "not implemented yet.\n";
			break;			
			case Input_T::course: {
				std::cout << "Hello User! Please enter name of course you want to add.\n";
				std::cin >> cn;
				Course c{ cn };
				courselist.push_back(c);
			}
			break;
			case Input_T::deadline: {
				std::cout << "Hello User! Please enter name of course where deadline belongs.\n";
				std::cin >> cn;
				int i=find_in_list(cn, courselist);
				courselist[i].add_deadline();
				break;
			}
			break;
			case Input_T::call: {
				std::cout << "Hello User! Please enter name of course you want deadlines of.\n";
				std::cin >> cn;
				int i = find_in_list(cn, courselist);
				courselist[i].duelist();
				break;
			}
			case Input_T::callall: {
				for (Course x : courselist) x.duelist();
				break;
			}
			case Input_T::quit: return 0;
		}				
	}
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
