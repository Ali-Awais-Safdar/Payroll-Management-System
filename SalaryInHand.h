#pragma once
#include <iostream>
#include <string>
#include "employee.h"
using namespace std;
#ifndef SALARYINHAND_H
#define SALARYINHAND_H
class Salary_In_Hand : public Employee {
protected:
	double CTC_salary;
	double bonus;
	double pf_deduction;
	double total_savings;
	double net_salary;
	string performance;
	double current_salary;
public:
	Salary_In_Hand(double, string, string, int, string, double);
	static double net_loss;
	virtual void get_details() = 0;
	virtual void set_details() = 0;
	virtual void write_to_file(string)=0;
};
#endif