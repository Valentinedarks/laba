#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    double baseSalary;

public:
    Employee(string n, int i, double bs) : name(n), id(i), baseSalary(bs) {
        if (bs < 0) baseSalary = 0;
    }

    virtual ~Employee() {}

    virtual double calculateSalary() const = 0;
    virtual void getInfo() const = 0;
    string getName() const { return name; }
    virtual string getType() const = 0;
};

class Manager : public Employee {
    int subordinates;
    double bonusPerSubordinate;
    double monthlyAllowancePercent;

public:
    Manager(string n, int i, double bs, int sub, double bps, double map)
        : Employee(n, i, bs), subordinates(sub < 0 ? 0 : sub),
          bonusPerSubordinate(bps < 0 ? 0 : bps), monthlyAllowancePercent(map < 0 ? 0 : map) {}

    double calculateSalary() const override {
        return baseSalary + (subordinates * bonusPerSubordinate) + (baseSalary * monthlyAllowancePercent / 100.0);
    }

    void getInfo() const override {
        cout << "[Менеджер] id: " << id << " | Ім'я: " << name
             << " | Підлеглих: " << subordinates
             << " | Зарплата: " << fixed << setprecision(2) << calculateSalary() << " грн" << endl;
    }

    string getType() const override { return "Manager"; }
};

class Freelancer : public Employee {
    int completedProjects;
    double payPerProject;
    double platformCommissionPercent;

public:
    Freelancer(string n, int i, double bs, int projects, double ppp, double pcp)
        : Employee(n, i, bs), completedProjects(projects < 0 ? 0 : projects),
          payPerProject(ppp < 0 ? 0 : ppp), platformCommissionPercent(pcp < 0 ? 0 : pcp) {}

    double calculateSalary() const override {
        double total = completedProjects * payPerProject;
        return total - (total * platformCommissionPercent / 100.0);
    }

    void getInfo() const override {
        cout << "[Фрілансер] id: " << id << " | Ім'я: " << name
             << " | Проєктів: " << completedProjects
             << " | Зарплата: " << fixed << setprecision(2) << calculateSalary() << " грн" << endl;
    }

    string getType() const override { return "Freelancer"; }
};

class Intern : public Employee {
    int hoursWorked;
    double hourlyRate;
    double stipendCoefficient;

public:
    Intern(string n, int i, double bs, int hours, double rate, double coeff)
        : Employee(n, i, bs), hoursWorked(hours < 0 ? 0 : hours),
          hourlyRate(rate < 0 ? 0 : rate), stipendCoefficient(coeff < 0 ? 0 : coeff) {}

    double calculateSalary() const override {
        return hoursWorked * hourlyRate * stipendCoefficient;
    }

    void getInfo() const override {
        cout << "[Стажер] id: " << id << " | Ім'я: " << name
             << " | Годин: " << hoursWorked
             << " | Зарплата: " << fixed << setprecision(2) << calculateSalary() << " грн" << endl;
    }

    string getType() const override { return "Intern"; }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    const int SIZE = 6;
    Employee* rabotnik[SIZE];

    rabotnik[0] = new Manager("Судеренко О.", 101, 15000, 5, 400, 10);
    rabotnik[1] = new Manager("Маменко М.", 102, 18000, 3, 500, 12);
    rabotnik[2] = new Freelancer("Стасенко М.", 201, 0, 5, 2500, 7);
    rabotnik[3] = new Freelancer("Алабєнко Ш.", 202, 0, 2, 6000, 10);
    rabotnik[4] = new Intern("Коробкович І.", 301, 0, 100, 80, 1.1);
    rabotnik[5] = new Intern("Параболенко Р.", 302, 0, 120, 80, 1.2);

    double totalFund = 0;
    double sumManager = 0, sumFreelancer = 0, sumIntern = 0;
    Employee* highestPaid = rabotnik[0];

    cout << "--- СИСТЕМА ОБЛІКУ ПЕРСОНАЛУ ---" << endl << endl;
    for (int i = 0; i < SIZE; i++) {
        rabotnik[i]->getInfo();
        double currentSalary = rabotnik[i]->calculateSalary();
        totalFund += currentSalary;
        if (currentSalary > highestPaid->calculateSalary()) {
            highestPaid = rabotnik[i];
        }
        string type = rabotnik[i]->getType();
        if (type == "Manager") sumManager += currentSalary;
        else if (type == "Freelancer") sumFreelancer += currentSalary;
        else if (type == "Intern") sumIntern += currentSalary;
    }

    cout << "\n--- АНАЛІТИКА ---" << endl;
    cout << "Загальний фонд оплати праці: " << totalFund << " грн" << endl;
    cout << "Середня заробітна плата: " << totalFund / SIZE << " грн" << endl;
    cout << "Найвища зарплата: " << highestPaid->getName() << " (" << highestPaid->calculateSalary() << " грн)" << endl;
    cout << "\n--- ВИПЛАТИ ЗА КАТЕГОРІЯМИ ---" << endl;
    cout << "Менеджери: " << sumManager << " грн" << endl;
    cout << "Фрілансери: " << sumFreelancer << " грн" << endl;
    cout << "Стажери: " << sumIntern << " грн" << endl;

    for (int i = 0; i < SIZE; i++) {
        delete rabotnik[i];
    }

    return 0;
}