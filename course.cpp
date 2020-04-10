#pragma once
#include "Header.h"

Course::Course(std::string n):
	name{ n }
{
	if (n.empty()) throw invalid{};
}

Course::Course() :
	name{ "" }
{	
}

void Course::duelist() {
	std::cout << name << ": \n";
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << "\n";
	}
}

std::ostream& operator<<(std::ostream& os, const Deadline& d) {
	return os << d.a_name << " due date: " << d.due << " type: " << print_type(d.kind);
}



Deadline Make_DL() {
	std::string s;
	Date d;
	int x;
	std::cout << "give name of deadline, leave empty if exam: ";
	std::cin >> s;
	std::cout << "give deadline in year_month_day: ";
	std::cin >> d;
	std::cout << "give typename of deadline: ";
	std::cin >> x;
	Deadline dl;
	dl.a_name = s;
	dl.due = d;
	dl.kind = D_Type(x);
	return dl;
}

void Course::add_deadline() {
	v.push_back(Make_DL());
}

std::string print_type(D_Type v) {
	std::string s;
	switch (v) {
	case D_Type::program:
		s = "Programming project";
		break;
	case D_Type::paper:
		s = "Essay or Programming report";
		break;
	case D_Type::combo:
		s = "Programming project and report on it";
		break;
	case D_Type::calc:
		s = "Math stuff";
		break;
	case D_Type::mid:
		s = "Midterm";
		break;
	case D_Type::exam:
		s = "Final exam";
		break;
	case D_Type::resit:
		s = "Resit exam";
		break;
	case D_Type::misc:
		s = "Unspecified";
		break;
	}
	return s;
}