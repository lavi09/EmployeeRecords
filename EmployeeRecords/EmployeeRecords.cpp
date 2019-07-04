// EmployeeRecords.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Database.h"

using namespace std;
using namespace EmployeeRecords;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int main()
{
	Database employeeDB;

	while (true)
	{
		int selection = displayMenu();
		switch (selection)
		{
		case 0:
			return 0;
		case 1:
			doHire(employeeDB);
			break;
		case 2:
			doFire(employeeDB);
			break;
		case 3:
			doPromote(employeeDB);
			break;
		case 4:
			employeeDB.displayAll();
			break;
		case 5:
			employeeDB.displayCurrent();
			break;
		case 6:
			employeeDB.displayFormer();
			break;
		default:
			cerr << "Unknown command.Try again" << endl;
			break;

		}
	}
	return 0;
}
int displayMenu()
{
	int selection;
	cout << endl;
	cout << "Employee database" << endl;
	cout << "---------------" << endl;
	cout << "1.Hire a new Employee"  << endl;
	cout << "2.Fire a new Employee" << endl;
	cout << "3.Promote an Employee" << endl;
	cout << "4.List all Employees" << endl;
	cout << "5.List all current Employees" << endl;
	cout << "6.List all Former Employees" << endl;
	cout << "7.Quit"<< endl;

	cin >> selection;
	return selection;

}
void doHire(Database& db)
{
	string firstName;
	string lastName;

	cout << "First name?";
	cin >> firstName;
	cout << "Last name?";
	cin >> lastName;

	db.addEmployee(firstName, lastName);


}
void doFire(Database& db)
{
	int employeeNumber;
	cout << "Employee number ?";
	cin >> employeeNumber;

	try
	{
		Employee& employee=db.getEmployee(employeeNumber);
		employee.fire();
		cout << "Employee" << employeeNumber << "terminated" << endl;

	}
	catch (const logic_error& exception)
	{
		cerr << "Unable to terminate the employee:" << exception.what()<<endl;

	}
}
void doPromote(Database& db)
{
	int employeeNumber;
	int raiseAmount;

	cout << "Employee number ?";
	cin >> employeeNumber;

	cout << "Raise Amount ?";
	cin >> raiseAmount;

	try
	{
		Employee& employee = db.getEmployee(employeeNumber);
		employee.promote();
		cout << "Employee" << employeeNumber << "Unable to promote" << endl;

	}
	catch (const logic_error& exception)
	{
		cerr << "Unable to promote employee:" << exception.what() << endl;

	}

}