#include <iostream>
using namespace std;
class Employee {
    protected:
        string empID;
        string empName;
        float hourlyRate;
        float grossPay;
        int hoursWorked;
        char name[size];
        int number;
    public:
        Employee() {
            cout << "An employee is being constructed." << endl;
        }
        void getName(char theName[]);
        int getNumber();
        void SetEmpID(string id) { 
            empID = id; 
        }
        string GetEmpID(){ 
            return empID; 
        }
        void SetName(string name) { 
            empName = name; 
        }
        string GetName(){ 
            return empName; 
        }
        void SetHourlyRate(float rate){ 
            hourlyRate = rate; 
        }
        float GetHourlyRate(){ 
            return hourlyRate; 
        }
    void SetHoursWorked(int hours){ 
        hoursWorked = hours; 
    }
    int GetHoursWorked(){ 
        return hoursWorked; 
    }
    float GetGrossPay(){ 
        return hourlyRate * hoursWorked; 
    }
    void Display() {
        cout << "Employee Record" << endl;
        cout << "Employee ID Number: " << empID << endl;
        cout << "Name: " << empName << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Hourly Wage: $" << hourlyRate << endl;
        cout << "Gross Pay: $" << GetGrossPay() << endl;
    }
};

class HourlyEmp : public Employee {
    private:
        float wageRate;
    public:
        HourlyEmp();
        float getWageRate() const;
    // use const so as not to change member values
};
int main() {
    // Test Employee class
    Employee emp;
    emp.SetEmpID("805");
    emp.SetName("Sammy Student");
    emp.SetHourlyRate(10.00);
    emp.SetHoursWorked(38);
    emp.Display();

    cout << "\n-----------------------\n";

    // Test SalaryEmployee class
    SalaryEmployee salEmp;
    salEmp.SetEmpID("837");
    salEmp.SetName("Samantha Student");
    salEmp.SetAnnualSalary(38000.00);
    salEmp.Display();

    return 0;
}