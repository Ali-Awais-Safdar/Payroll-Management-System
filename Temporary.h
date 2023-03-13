#pragma once
#include <iostream>
#include <string>
#include "employee.h"
#include "SalaryInHand.h"
using namespace std;
#ifndef TEMPORARY_H
#define TEMPORARY_H
class TemporaryEmployee :public Salary_In_Hand {
protected:
	double hours_per_week;
	double rate_per_hour;
public:
	TemporaryEmployee(double, double, string,  string, int, string, double);
	void get_details();
	void set_details();
	void write_to_file(string);
};
#endif