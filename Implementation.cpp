#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include "employee.h"
#include "SalaryInHand.h"
#include "Permanent.h"
#include "Temporary.h"
using namespace std;
double Salary_In_Hand::net_loss = 0.0;
Employee::Employee(string x, int y, string z, double w) :ID(y) {
	name = x;
	designation = z;
	experience = w;
}

Salary_In_Hand::Salary_In_Hand(double a,string b, string e, int f, string g, double h) : Employee(e, f, g, h) {
	CTC_salary = 0.0;
	bonus = a;
	pf_deduction = 0.0;
	total_savings = 0.0;
	net_salary = 0.0;
	performance = b;
	current_salary = 0.0;
}
PermanentEmployee::PermanentEmployee(double a, double b,  double f,string d, string g, int h, string i, double j) : Salary_In_Hand( f,d, g, h, i, j) {
	retainer = a;
	years_of_service = b;
}
TemporaryEmployee::TemporaryEmployee(double a,   double f,string d, string g, int h, string i, double j) : Salary_In_Hand( f,d, g, h, i, j) {
	hours_per_week = a;
	rate_per_hour = 0.0;
}
void PermanentEmployee::set_details() {
	if (experience > 2 && (performance=="A" || performance=="B")) {
		current_salary = 250000.0;
	}
	else {
		current_salary = 180000.0;
	}
	CTC_salary = current_salary + bonus + retainer;
	pf_deduction = 0.12 * CTC_salary;
	net_salary = CTC_salary - pf_deduction;
	total_savings = years_of_service * 12 * pf_deduction;
	net_loss = net_loss + (net_salary * 12 * years_of_service);
}
void TemporaryEmployee::set_details() {
	if (experience > 2 && (performance == "A" || performance == "B")) {
		rate_per_hour = 2800;
	}
	else {
		rate_per_hour = 1800;
	}
	current_salary = hours_per_week * rate_per_hour * 4;
	CTC_salary = current_salary + bonus;
	pf_deduction = 0.12 * CTC_salary;
	net_salary = CTC_salary - pf_deduction;
	total_savings = 12*pf_deduction;
	net_loss = net_loss + (net_salary * 12);
}
void PermanentEmployee::get_details() {
	cout << "The employee " << name << ", ID " << ID << " has served " << years_of_service << " years. " << "\n";
	cout << "Their salary per month is " << current_salary << ". After considering bonuses and retainers it becomes " << CTC_salary << "." << "\n";
	cout << "The provident fund deduction is " << pf_deduction << ". This makes the net salary " << net_salary << "."<<"\n";
	cout << "The net savings for the employee are " << total_savings << " due to the provident fund." << "\n";
	cout << "The net money spent for the company is " << net_loss << "\n";
}
void TemporaryEmployee::get_details() {
	cout << "The employee " << name << ", ID " << ID << " serves " << hours_per_week << " hours a week. Their hourly rate is "<<rate_per_hour<<"." << "\n";
	cout << "Their salary per month is " << current_salary << ". After considering bonuses and retainers it becomes " << CTC_salary << "." << "\n";
	cout << "The provident fund deduction is " << pf_deduction << ". This makes the net salary " << net_salary << "." << "\n";
	cout << "The net savings for the employee are " << total_savings << " due to the provident fund." << "\n";
	cout << "The net money spent for the company is " << net_loss << "\n";
}

void PermanentEmployee::write_to_file(string a) {
	fstream x1;
	x1.open(a + ".txt", ios::app);
	if (!x1)
	{
		cout << "Error in creating file!!!";
	}
	cout << "File created successfully." << endl;
	x1 << "Status:Permanent Faculty" << endl << "ID: " << ID << endl << "Name: " << name << endl << "Designation: " << designation << endl << "Experience: " << experience << endl << "Bonus: Rs" << bonus << endl << "Retainer: Rs" << retainer << endl << "Performance: " << performance << endl << "CTC salary: Rs" << CTC_salary << endl << "Current salary: Rs" << current_salary << endl << "Net salary: Rs" << net_salary << endl << "Provident fund deduction: Rs" << pf_deduction << endl << "Years served for employee: " << years_of_service << endl << "Net savings for emplyee: Rs" << total_savings << endl << "Net loss of company : Rs" << net_loss << endl;
	x1.close();
}
void TemporaryEmployee::write_to_file(string a) {
	fstream z1;
	z1.open(a + ".txt", ios::app);
	if (!z1)
	{
		cout << "Error in creating file!!!";
	}
	cout << "File created successfully." << endl;
	z1 << "Status: Visiting Faculty" << endl << "ID: " << ID << endl << "Name: " << name << endl << "Designation: " << designation << endl << "Experience: " << experience << endl << "Bonus: Rs" << bonus << endl << "Hours per week: " << hours_per_week << endl << "Performance: " << performance << endl << "CTC salary: Rs" << CTC_salary << endl << "Current salary: Rs" << current_salary << endl << "Net salary: Rs" << net_salary << endl << "Provident fund deduction: Rs" << pf_deduction << endl << "Rate per hour: " << rate_per_hour << endl << "Net savings for emplyee: Rs" << total_savings << endl << "Net loss of company: Rs" << net_loss << endl;
	z1.close();
}
