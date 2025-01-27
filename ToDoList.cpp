#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

void addTask(vector<Task> &tasks) {
    string task;
    cout << "Enter the task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back({task, false});
    cout << "Task added successfully." << endl;
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    } else {
        cout << "\nTasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed." << endl;
    } else {
        viewTasks(tasks);
        cout << "Enter the task number to mark as completed: ";
        int taskNum;
        cin >> taskNum;

        if (taskNum > 0 && taskNum <= tasks.size()) {
            tasks[taskNum - 1].completed = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}

void removeTask(vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to remove." << endl;
    } else {
        viewTasks(tasks);
        cout << "Enter the task number to remove: ";
        int taskNum;
        cin >> taskNum;

        if (taskNum > 0 && taskNum <= tasks.size()) {
            cout << "Task '" << tasks[taskNum - 1].description << "' removed successfully." << endl;
            tasks.erase(tasks.begin() + taskNum - 1);
        } else {
            cout << "Invalid task number." << endl;
        }
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        cout << "\nEnter your choice: ";
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
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
