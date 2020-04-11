
#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class D_Type {
	program=1, paper, combo, calc, exam, mid, resit, misc
};

enum class Input_T {
	load, save, course, deadline, list, call, callall, quit, error
};

class Date {
public:
	class invalid {};
	Date(int y, Month m, int d);
	Date();
	int day() const { return d; }
	Month month() const  { return m; }
	int year() const { return y; }

	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
private:
	int y; //year 
	int d; //day
	Month m;
};

class Deadline: public Date{
public:
	Deadline(int y, Month m, int d, std::string s, D_Type dt);
	std::string give_name() const { return a_name; }
	D_Type give_kind() const { return kind; }
private:
	std::string a_name;	
	D_Type kind;
};

class Course {
public:
	class invalid {};
	Course(std::string name);
	Course();
	void duelist(); //prints list of deadlines in course
	void add_deadline();
	std::string r_name() { return name; };
private:
	std::string name;
	std::vector<Deadline> v;
};



bool is_date(int, Month, int);

std::ostream& operator<<(std::ostream& os, const Date& d);

std::istream& operator>>(std::istream& is, Date& d);

std::ostream& operator<<(std::ostream& os, const Deadline& d);

std::string print_type(D_Type v);

Deadline Make_DL();

void print_menu();

Input_T command(std::string s);

int find_in_list(std::string s, std::vector<Course> v);