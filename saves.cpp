#pragma once
#include "Header.h"

void print_menu() {
	std::cout << "Hello User! Enter a command\n";
	std::cout << " \'load\' to load list from savefile,\n";
	std::cout << "\'save\' to save current list to file (will overwrite, load first to make changes, then save)\n";
	std::cout << "\'course\' to add course to list \n";
	std::cout << "\'deadline\' to add deadline to a course (selection after) \n";
	std::cout << "\'list\'  to print list of courses \n";
	std::cout << "'\cal\' to print deadlines of a course \n";
	std::cout << "\'calall\' to print deadlines of all courses\n";
	std::cout << "\'quit\' to quit program\n";
}

Input_T command(std::string s) {	
	if (s == "load") return Input_T::load;
	if (s == "save") return Input_T::save;
	if (s == "course") return Input_T::course;
	if (s == "deadline") return Input_T::deadline;
	if (s == "list") return Input_T::list;
	if (s == "cal") return Input_T::call;
	if (s == "calall") return Input_T::callall;
	if (s == "quit") return Input_T::quit;
	return Input_T::error;
}

int find_in_list(std::string s, std::vector<Course> v) {	
	for (int i = 0; i < v.size(); i++) {
		if (v[i].r_name() == s) {
			std::cout << "success\n";
			return i;
		}
	}
	return -1;
}