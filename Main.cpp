#include <iostream>
#include <string>
#include "employee.h"
#include "SalaryInHand.h"
#include "Permanent.h"
#include "Temporary.h"
#include <fstream>
#include<sstream>
using namespace std;
bool show_menu();
void create_permemp();
void create_tempemp();
void get_emp();
void edit_data();
int main() {
	while (show_menu());
	show_menu();
}
bool show_menu() {
	cout << "\t********Payroll Management System***********\t" << "\n";
	cout << "1. \t Create a permanent employee's record"<<endl;
	cout << "2. \t Create a visiting employee's record" << endl;
	cout << "3. \t Show details of an employee" << endl;
	cout << "4. \t Edit record of an employee" << endl;
	cout << "5. \t Quit" << endl;
	int choice = 0;
invalidMain:
	cout << "Enter your choice: ";
	cin >> choice;
	switch (choice) {
	case 1:
		create_permemp();
		break;
	case 2:
		create_tempemp();
		break;
	case 3:
		get_emp();
		break;
	case 4:
		edit_data();
		break;
	case 5:
		return false;
		break;
	default:
		cout << "Invalid choice" << "\n";
		goto invalidMain;
		break;
	}
	return true;
}

void create_permemp() {
	string name, designation;
	int ID;
	double experience;
	double bonus;
	string performance;
	double retainer;
	double years_of_service;
	cout << "Enter employee name:  ";
	cin >> name;
	cout << "Enter ID:  ";
	cin >> ID;
	while (ID / 1000000 > 0) {
		cout << "The ID has to be six digits, please enter it again \n";
		cout << "Enter ID:  ";
		cin >> ID;
	}
	cout << "Enter the designation:  ";
	cin >> designation;
	cout << "Enter the experience of the employee:  ";
	cin >> experience;
	cout << "Enter the bonus the employee will have:  ";
	cin >> bonus;
	cout << "Enter the performance grade of the employee:  ";
	cin >> performance;
	cout << "Enter the retainer given to the employee:  ";
	cin >> retainer;
	cout << "Enter the years the employee has served:  ";
	cin >> years_of_service;
	PermanentEmployee P(retainer, years_of_service, bonus, performance, name, ID, designation, experience);
	P.set_details();
	Salary_In_Hand* E;
	E = &P;
	E->write_to_file(to_string(ID));
}


void create_tempemp() {
	string name, designation;
	int ID;
	double experience;
	double bonus;
	string performance;
	double hours_per_week;
	cout << "Enter employee name:  ";
	cin >> name;
	cout << "Enter ID:  ";
	cin >> ID;
	while (ID / 1000000 > 0) {
		cout << "The ID has to be six digits, please enter it again \n";
		cout << "Enter ID:  ";
		cin >> ID;
	}
	cout << "Enter the designation:  ";
	cin >> designation;
	cout << "Enter the experience of the employee:  ";
	cin >> experience;
	cout << "Enter the bonus the employee will have:  ";
	cin >> bonus;
	cout << "Enter the performance grade of the employee:  ";
	cin >> performance;
	cout << "Enter the hours the employee serves per week:  ";
	cin >> hours_per_week;
	TemporaryEmployee Q(hours_per_week, bonus, performance, name, ID, designation, experience);
	Q.set_details();
	Salary_In_Hand* E = &Q;
	E->write_to_file(to_string(ID));
}

void get_emp() {
	int ID;
	cout << "Enter Employee's ID: ";
	cin >> ID;
	string fileName = to_string(ID) + ".txt";
	ifstream f(fileName);
	if (f.is_open())
		cout << "\n\n" << f.rdbuf() << "\n\n" << endl;
}

string getdata(string filename, string data) {

	string fileName = filename + ".txt";
	fstream file;
	string word;
	int iter = 0;
	file.open(fileName.c_str());
	while (file >> word && iter <= 1) {
		if (word == data) {
			iter++;
		}
		if (iter == 1 && word != data) {
			break;
		}
	}
	file.close();
	return word;
}

void edit_data() {

	int ID;
	cout << "Enter Employee's ID: ";
	cin >> ID;
	int choice;
	cout << "What data do you want to change? " << endl;
	cout << "1. \t Name" << endl;
	cout << "2. \t Designation" << endl;
	cout << "3. \t Experience" << endl;
	string new_word, filename, str, old;
invalidchange:
	cin >> choice;
	switch (choice) {
	case 1:
		old = getdata(to_string(ID), "Name:");
		break;
	case 2:
		old = getdata(to_string(ID), "Designation:");
		break;
	case 3:
		old = getdata(to_string(ID), "Experience:");
		break;
	default:
		goto invalidchange;
		break;
	}
	cout << "Current Data is : " << old << endl;

	int i = 0, cpos;
	stringstream text;//Creating a string stream to store the data of a file
	fstream file_ob; //creating an input/output stream

	filename = to_string(ID) + ".txt";
	cout << "Enter the new data to replace old one: ";
	cin >> new_word;
	file_ob.open(filename.c_str(), ios::in | ios::out | ios::binary);//opening a file
	text << file_ob.rdbuf();                     //now  the content of file is present in text.str()
	str = text.str();

	size_t pos = str.find(old);                   //finding first occurence of substring 
	while (pos != std::string::npos)             // Repeat till the end is reached
	{
		if (pos == 0)
			cpos = pos + old.size();
		else
			cpos = pos - 1;
		if ((isspace(str[cpos]) || ispunct(str[cpos])) && (isspace(str[pos + old.size()])) || ispunct(str[pos + old.size()]))                               //Checking whether found substring is a word or not
		{
			str.replace(pos, old.length(), new_word);
			i++;
		}
		pos = str.find(old, pos + old.size() + 1);     // Get the next occurrence from the current position
	}
	if (i > 0)
		cout << " *********Your file has been modified**********" << endl;
	ofstream write_file(filename.c_str(), ios::binary);
	write_file << str;
	file_ob.clear();
	file_ob.close();
}
