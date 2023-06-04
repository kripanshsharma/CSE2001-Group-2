#include <iostream>
using namespace std;

class Employee //base class-abstract class
{
    //scope - visibility, accessibility
    //data abstraction
protected:
    double salary;
    int projectCompleted;
    int attendence;
    int totalWorkingDays;

public:
    double ID;
    string name;
    string department;

    Employee(int ID, string name, string department, int projectCompleted, int attendence, int totalWorkingDays, double salary) //constructor
    {
        //instance variable = local variable
        this->ID = ID;
        this->name = name;
        this->department = department;
        this->projectCompleted = projectCompleted;
        this->attendence = attendence;
        this->totalWorkingDays = totalWorkingDays;
        this->salary = salary;
    }

    virtual void appraiseSalary() = 0; //pure virtual function

    ~Employee() {} //destructor
};

class Manager : virtual public Employee //inherited class
{
public:
    Manager(int ID, string name, string department, int projectCompleted, int attendence, int totalWorkingDays, double salary) : Employee(ID, name, department, projectCompleted, attendence, totalWorkingDays, salary)
    {
    }

    virtual void appraiseSalary()
    {
        int cutoff = (50 * totalWorkingDays) / 100;
        if (projectCompleted > 0 && attendence >= cutoff)
        {
            float appraisal = (10 * salary) / 100;
            cout << '\n';
            cout << "Congratulations on a pay raise! Keep it up :)" << endl;
            cout << "Salary after appraisal: Rs." << salary + appraisal << "\n\n";
        }
        else
        {
            try
            {
                if (projectCompleted == 0)
                {
                    throw projectCompleted;
                }
            }

            catch (int projectCompleted)
            {
                cout << "Sorry! You are asshole. No appraisal for you.  \n\n";
            }

            try
            {
                if (attendence < cutoff)
                {
                    throw attendence;
                }
            }

            catch (int attendence)
            {
                cout << "Sorry! Your attendence is not sufficient. No appraisal for you \n\n";
            }
        }
    }
    //inline function copies function code in main method making code run fast
    //but it takes more memory.
    inline virtual void display()
    {
        cout << "Employee Id: " << ID << endl;
        cout << "Employee Name: " << name << endl;
        cout << "department name " << department << endl;
        cout << "No. of projects completed: " << projectCompleted << endl;
        cout << "No. of days worked: " << attendence << endl;
        cout << "Total no. of working days: " << totalWorkingDays << endl;
        cout << "Current salary: Rs." << salary << endl
             << endl;
    }
    //default agrument function
    virtual void display(Manager m, int projectCompleted = 0) //function overloading
    {
        cout << "Employee name :" << m.name << endl;
        cout << "Employee ID :" << projectCompleted << endl;
    }

    ~Manager() {} //destructor
};

class GeneralManager : public virtual Employee
{
public:
    GeneralManager() : Employee(ID, name, department, projectCompleted, attendence, totalWorkingDays, salary) {}

    // redefining inherited function
    // polymorphism, this polymorphism is function overriding
    void display()
    {
        cout << "GeneralManager display\n";
    }

    void display(string department) //function overloading
    {
        cout << projectCompleted << endl;
    }

    ~GeneralManager() {} //destructor
};

class Bonus
{
private:
    int trophies;

public:
    int ID;
    string name;

    Bonus(int ID, string name, int trophies)
    {
        this->ID = ID;
        this->name = name;
        this->trophies = trophies;
    }

    void operator>(Bonus temp)
    {
        if (trophies > temp.trophies)
        {
            cout << name << " has the maximum trophies\n";
            cout << name << " will get a bonus of Rs." << trophies * 10000 << "\n\n";
        }
        else
        {
            cout << temp.name << " has the maximum trophies\n";
            cout << temp.name << " will get a bonus of Rs." << temp.trophies * 10000 << "\n";
        }
    }

    friend void print();
};

void print()
{
    Bonus a = Bonus(200186, "Bob", 6);
    Bonus b = Bonus(200187, "Rob", 3);
    cout << "Trophies earned by " << a.name << " is: " << a.trophies << endl;
    cout << "Trophies earned by " << b.name << " is: " << b.trophies << endl;
}

int main()
{
    Bonus c1 = Bonus(200186, "Bob", 6);
    Bonus c2 = Bonus(200187, "Rob", 3);
    print();
    c1 > c2;
    Manager m1 = Manager(200186, "Bob", "Marketing", 3, 253, 300, 300000);
    Manager m2 = Manager(200187, "Rob", "Sales", 4, 240, 300, 400000);
    m1.display();      //compile time polymorphism
    m1.display(m1, 2); //compile time polymorphism
    m1.appraiseSalary();
    Manager *m;   //declaring pointer
    m = &m1;      //&m1 deonotes address of m1;
    m->display(); //runtime polymorphism
    m = &m2;      //&m2 deonotes address of m2;
    m->display(); //runtime polymorphism
    return 0;
}
