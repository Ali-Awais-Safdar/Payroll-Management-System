#pragma once
#include <iostream>
#include <string>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;

class Employee {
protected:
	string name;
	const int ID;
	string designation;
	double experience;
public:
	Employee(string,int,string,double);
	virtual void get_details() = 0;
	virtual void set_details() = 0;
};

#endif


