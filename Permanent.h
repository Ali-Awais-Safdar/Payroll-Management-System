#pragma once
#include <iostream>
#include <string>
#include "employee.h"
#include "SalaryInHand.h"
using namespace std;
#ifndef PERMANENT_H
#define PERMANENT_H
class PermanentEmployee:public Salary_In_Hand {
protected:
	double retainer;
	double years_of_service;
public:
	PermanentEmployee(double,double,double,string,  string, int, string, double);
	void get_details();
	void set_details();
	void write_to_file(string);
};


#endif
