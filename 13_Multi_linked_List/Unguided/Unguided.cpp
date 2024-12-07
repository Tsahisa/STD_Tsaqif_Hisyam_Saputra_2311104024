#include <iostream>
#include <string>
using namespace std;

struct Project {
    string projectName;
    int duration;
    Project* next;
};

struct Employee {
    string name;
    string id;
    Project* projectHead;
    Employee* next;
};

class EmployeeProjectManager {
private:
    Employee* head;

public:
    EmployeeProjectManager() : head(nullptr) {}

    void addEmployee(const string& name, const string& id) {
        Employee* newEmployee = new Employee{name, id, nullptr, head};
        head = newEmployee;
    }

    void addProjectToEmployee(const string& employeeId, const string& projectName, int duration) {
        Employee* emp = findEmployee(employeeId);
        if (emp) {
            Project* newProject = new Project{projectName, duration, emp->projectHead};
            emp->projectHead = newProject;
        } else {
            cout << "Employee with ID " << employeeId << " not found.\n";
        }
    }

    void removeProjectFromEmployee(const string& employeeId, const string& projectName) {
        Employee* emp = findEmployee(employeeId);
        if (emp) {
            Project* prev = nullptr;
            Project* current = emp->projectHead;
            while (current) {
                if (current->projectName == projectName) {
                    if (prev) {
                        prev->next = current->next;
                    } else {
                        emp->projectHead = current->next;
                    }
                    delete current;
                    cout << "Project " << projectName << " removed from employee " << emp->name << ".\n";
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "Project " << projectName << " not found for employee " << emp->name << ".\n";
        } else {
            cout << "Employee with ID " << employeeId << " not found.\n";
        }
    }

    void displayAll() {
        Employee* emp = head;
        while (emp) {
            cout << "Employee Name: " << emp->name << ", ID: " << emp->id << "\n";
            Project* proj = emp->projectHead;
            if (proj) {
                cout << "  Projects:\n";
                while (proj) {
                    cout << "    - " << proj->projectName << " (Duration: " << proj->duration << " months)\n";
                    proj = proj->next;
                }
            } else {
                cout << "  No projects assigned.\n";
            }
            emp = emp->next;
        }
    }

private:
    Employee* findEmployee(const string& id) {
        Employee* current = head;
        while (current) {
            if (current->id == id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
};

int main() {
    EmployeeProjectManager manager;

    // Adding employees
    manager.addEmployee("Andi", "P001");
    manager.addEmployee("Budi", "P002");
    manager.addEmployee("Citra", "P003");

    // Adding projects
    manager.addProjectToEmployee("P001", "Aplikasi Mobile", 12);
    manager.addProjectToEmployee("P002", "Sistem Akuntansi", 8);
    manager.addProjectToEmployee("P003", "E-commerce", 10);

    // Adding a new project to Andi
    manager.addProjectToEmployee("P001", "Analisis Data", 6);

    // Removing a project from Andi
    manager.removeProjectFromEmployee("P001", "Aplikasi Mobile");

    // Display all employees and their projects
    manager.displayAll();

    return 0;
}
