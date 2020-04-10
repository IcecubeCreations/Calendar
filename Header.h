
#pragma once

#include <iostream>
#include <vector>
#include <string>


enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class D_Type {
	program=1, paper, combo, calc, exam, mid, resit, misc
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

struct Deadline {
	std::string a_name;
	Date due;
	D_Type kind;
};

class Course {
public:
	class invalid {};
	Course(std::string name);
	Course();
	void duelist(); //prints list of deadlines in course
	void add_deadline();
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
