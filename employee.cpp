#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a Task assigned to an employee
class Task
{
private:
    string description;
    string status; // Can be "Pending", "In Progress", or "Completed"

public:
    // Constructor
    Task(string desc) : description(desc), status("Pending") {}

    // Getters and setters for task description and status
    string getDescription() const { return description; }
    string getStatus() const { return status; }

    void setStatus(const string &newStatus) { status = newStatus; }

    // Display task details
    void display() const
    {
        cout << "Task: " << description << ", Status: " << status << endl;
    }
};

// Class representing an Employee
class Employee
{
private:
    int id;
    string name;
    vector<Task> tasks; // List of tasks assigned to the employee

public:
    // Constructor
    Employee(int eid, string ename) : id(eid), name(ename) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }

    // Assign a new task to the employee
    void assignTask(const Task &task)
    {
        tasks.push_back(task);
    }

    // View all tasks assigned to the employee
    void viewTasks() const
    {
        cout << "Tasks for Employee: " << name << " (ID: " << id << ")" << endl;
        if (tasks.empty())
        {
            cout << "No tasks assigned." << endl;
        }
        else
        {
            for (const auto &task : tasks)
            {
                task.display();
            }
        }
    }

    // Update the status of a specific task
    void updateTaskStatus(int taskIndex, const string &newStatus)
    {
        if (taskIndex >= 0 && taskIndex < tasks.size())
        {
            tasks[taskIndex].setStatus(newStatus);
            cout << "Task status updated." << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }
};

// Class to manage the entire system
class EmployeeWorkManagement
{
private:
    vector<Employee> employees;

public:
    // Add a new employee to the system
    void addEmployee(int id, const string &name)
    {
        employees.push_back(Employee(id, name));
        cout << "Employee added: " << name << " (ID: " << id << ")" << endl;
    }

    // Assign a task to an employee by their ID
    void assignTaskToEmployee(int employeeId, const string &taskDescription)
    {
        for (auto &employee : employees)
        {
            if (employee.getId() == employeeId)
            {
                employee.assignTask(Task(taskDescription));
                cout << "Task assigned to " << employee.getName() << endl;
                return;
            }
        }
        cout << "Employee with ID " << employeeId << " not found." << endl;
    }

    // View tasks of a specific employee by their ID
    void viewEmployeeTasks(int employeeId) const
    {
        for (const auto &employee : employees)
        {
            if (employee.getId() == employeeId)
            {
                employee.viewTasks();
                return;
            }
        }
        cout << "Employee with ID " << employeeId << " not found." << endl;
    }

    // Update task status of a specific employee by their ID
    void updateTaskStatus(int employeeId, int taskIndex, const string &newStatus)
    {
        for (auto &employee : employees)
        {
            if (employee.getId() == employeeId)
            {
                employee.updateTaskStatus(taskIndex, newStatus);
                return;
            }
        }
        cout << "Employee with ID " << employeeId << " not found." << endl;
    }

    // View all employees in the system
    void viewAllEmployees() const
    {
        cout << "Employees in the system:" << endl;
        for (const auto &employee : employees)
        {
            cout << "ID: " << employee.getId() << ", Name: " << employee.getName() << endl;
        }
    }
};

// Function to display the main menu
void displayMenu()
{
    cout << "\nEmployee Work Management System Menu:" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. View All Employees" << endl;
    cout << "3. Assign Task to Employee" << endl;
    cout << "4. View Employee Tasks" << endl;
    cout << "5. Update Task Status" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    EmployeeWorkManagement system;
    int choice, employeeId, taskIndex;
    string name, taskDescription, newStatus;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Add a new employee
            cout << "Enter Employee ID: ";
            cin >> employeeId;
            cout << "Enter Employee Name: ";
            cin.ignore(); // To ignore the newline character from previous input
            getline(cin, name);
            system.addEmployee(employeeId, name);
            break;

        case 2:
            // View all employees
            system.viewAllEmployees();
            break;

        case 3:
            // Assign a task to an employee
            cout << "Enter Employee ID to assign task: ";
            cin >> employeeId;
            cout << "Enter Task Description: ";
            cin.ignore();
            getline(cin, taskDescription);
            system.assignTaskToEmployee(employeeId, taskDescription);
            break;

        case 4:
            // View tasks of a specific employee
            cout << "Enter Employee ID to view tasks: ";
            cin >> employeeId;
            system.viewEmployeeTasks(employeeId);
            break;

        case 5:
            // Update the status of a task
            cout << "Enter Employee ID: ";
            cin >> employeeId;
            cout << "Enter Task Index (0 for first task, 1 for second, etc.): ";
            cin >> taskIndex;
            cout << "Enter New Status (Pending/In Progress/Completed): ";
            cin.ignore();
            getline(cin, newStatus);
            system.updateTaskStatus(employeeId, taskIndex, newStatus);
            break;

        case 6:
            // Exit
            cout << "Exiting system..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
