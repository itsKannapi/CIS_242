#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string empID;
    string empName;
    float hourlyRate;
    float grossPay;
    int hoursWorked;

public:
    Employee() {
        cout << "An Employee is being constructed." << endl;
    }

    void SetEmpID(string ID) {
        empID = ID;
    }
    string GetEmpID() {
        return empID;
    }

    void SetName(string name) {
        empName = name;
    }
    string GetName() {
        return empName;
    }

    void SetHourlyRate(float rate) {
        hourlyRate = rate;
    }
    float GetHourlyRate() {
        return hourlyRate;
    }

    void SetHoursWorked(int hours) {
        hoursWorked = hours;
    }
    int GetHoursWorked() {
        return hoursWorked;
    }

    float GetGrossPay() {
        grossPay = hourlyRate * hoursWorked;
        return grossPay;
    }

    void Display() {
        cout << "Employee Record\n";
        cout << "ID Number: " << empID << endl;
        cout << "Name: " << empName << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Wage: $" << hourlyRate << endl;
        cout << "Gross Pay: $" << GetGrossPay() << endl;
    }
};

class SalaryEmp : public Employee {
    private:
        float annualSalary;

    public:
        SalaryEmp() {
            cout << "A Salaried Employee is being constructed." << endl;
        }

    void SetAnnualSalary(float salary){
        annualSalary = salary;
    }
    float GetAnnualSalary(){
        return annualSalary * 1.005;
    }

    float GetGrossPay(){
        return annualSalary / 26;
    }

    void Display() {
        cout << "Salaried Employee Record\n";
        cout << "ID Number: " << empID << endl;
        cout << "Name: " << empName << endl;
        cout << "Annual Salary: $" << annualSalary << endl;
        cout << "Bi-Weekly Gross Pay: $" << GetGrossPay() << endl;
    }
};

int main() {
    // Test Employee class
    Employee emp;
    emp.SetEmpID("727");
    emp.SetName("Sammy Student");
    emp.SetHourlyRate(14.50);
    emp.SetHoursWorked(38);
    emp.Display();

    cout << "\n--------------------------\n";

    // Test SalaryEmp class
    SalaryEmp salEmp;
    salEmp.SetEmpID("999");
    salEmp.SetName("Samantha Student");
    salEmp.SetAnnualSalary(38000.00);
    salEmp.Display();

    return 0;
}
