#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks) {
    cin.ignore(); 
    string description;
    cout << "Enter the task description: ";
    getline(std::cin, description);
    tasks.push_back(Task(description));
    cout << "Task added." << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display." << std::endl;
        return;
    }
    cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " [Completed]";
        }
        cout << std::endl;
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number." << std::endl;
        return;
    }

    tasks[index - 1].completed = true;
    cout << "Task marked as completed." << std::endl;
}

void removeTask(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;

    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > static_cast<int>(tasks.size())) {
        cout << "Invalid task number." << std::endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed." << std::endl;
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting. Goodbye!" << std::endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }
    }
}
