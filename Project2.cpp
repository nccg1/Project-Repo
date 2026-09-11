#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
	string name;

public:
	Employee(string employeeName)
	{
		name = employeeName;
	}

	virtual double calculatePay()
	{
		return 0.0;
	}

	string getName()
	{
		return name;
	}
};

class SalariedEmployee : public Employee
{
private:
	double monthlySalary;

public:
	SalariedEmployee(string employeeName, double salary)
		: Employee(employeeName)
	{
		monthlySalary = salary;
	}

	double calculatePay() override
	{
		return monthlySalary;
	}
};

class HourlyEmployee : public Employee
{
private:
	double hourlyRate;
	double hoursWorked;

public:
	HourlyEmployee(string employeeName, double rate, double hours)
		: Employee(employeeName)
	{
		hourlyRate = rate;
		hoursWorked = hours;
	}

	double calculatePay() override
	{
		return hourlyRate * hoursWorked;
	}
};

int main()
{
	SalariedEmployee salaried("Alice", 4000.00);
	HourlyEmployee hourly("Bob", 20.00, 80);

	Employee* employees[2] = { &salaried, &hourly };

	for (int i = 0; i < 2; i++)
	{
		cout << employees[i]->getName() << " earns $"
			 << employees[i]->calculatePay() << endl;
	}

	return 0;
}
