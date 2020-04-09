#pragma once
#include "Header.h"

Date::Date(int yy, Month mm, int dd) 
	:y{ yy }, m{ mm }, d{ dd }
{
	if (!is_date(yy, mm, dd)) throw invalid{};
};

const Date& default_date() {
	static Date dd{ 2000, Month::jan, 1 };
	return dd;
};

Date::Date() 
	:y{default_date().year()},
	m{default_date().month()},
	d{default_date().day()}
{
}


void Date::add_year(int n) {
	y += n;
}

void Date::add_month(int n) {
	int max_months = 12;
	int current;
	current = int(month());	
	int year=0;

	while (current + n > max_months) {
		n -= max_months;
		year++;
	}	
	if (year > 0) add_year(year);
	current += n;	
	m = Month(current);
}

void Date::add_day(int n) {
	int max_days = 31; //most common amount of days in month
	switch (m) {
	case Month::feb:
		max_days = 28; //not counting leap years!
		break;
	case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		max_days = 30;
		break;
	}	
	if (d + n > max_days) {
		n -= max_days;
		add_month(1);
		add_day(n);
	}
	else d += n;
}

bool is_date(int y, Month m, int d) {
	if (d <= 0) return false; //day must be positive value
	if (m<Month::jan || m>Month::dec) return false; //not a valid month
	if (y < 1800 || y > 2200) return false; //artificial constraint

	int max_days = 31; //most common amount of days in month
	switch (m) {
	case Month::feb:
		max_days = 28; //not counting leap years!
	case Month::apr: case Month::jun: case Month::sep: case Month::nov:
		max_days = 30;
	}
	if (max_days < d) return false;

	return true;
};

std::ostream& operator<<(std::ostream& os, const Date& d) {
	return os << '(' << d.year() << ',' << int(d.month()) << ',' << d.day() << ')';
}

std::istream& operator>>(std::istream& is, Date& dd) {
	int y, m, d;
	is >> y >> m >> d;
	dd = Date( y, Month(m), d ); //needs proofing
	return is;
}