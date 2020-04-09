
#pragma once

#include <iostream>


enum class Month {
	jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
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

bool is_date(int, Month, int);

std::ostream& operator<<(std::ostream& os, const Date& d);

std::istream& operator>>(std::istream& is, Date& d);