#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task> &taskList, const string &description);
void viewTasks(const vector<Task> &taskList);
void markTaskAsCompleted(vector<Task> &taskList, const string &description);
void removeTask(vector<Task> &taskList, const string &description);

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "\nTask Management Menu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter the task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(taskList, taskDescription);
                break;
            }
            case 2:
                viewTasks(taskList);
                break;
            case 3: {
                string taskDescription;
                cout << "Enter the task description to mark as completed: ";
                cin.ignore(); 
                getline(cin, taskDescription);
                markTaskAsCompleted(taskList, taskDescription);
                break;
            }
            case 4: {
                string taskDescription;
                cout << "Enter the task description to remove: ";
                cin.ignore(); // Ignore newline character from previous input
                getline(cin, taskDescription);
                removeTask(taskList, taskDescription);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                break;
        }
    }

    return 0;
}

void addTask(vector<Task> &taskList, const string &description) {
    Task newTask = {description, false};
    taskList.push_back(newTask);
    cout << "Task added successfully.\n";
}

void viewTasks(const vector<Task> &taskList) {
    cout << "\nTask List:\n";
    for (const Task &task : taskList) {
        cout << "- " << task.description << " [" << (task.completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskAsCompleted(vector<Task> &taskList, const string &description) {
    auto it = find_if(taskList.begin(), taskList.end(), [&](const Task &task) {
        return task.description == description;
    });

    if (it != taskList.end()) {
        it->completed = true;
        cout << "Task marked as completed.\n";
    } else {
        cout << "Task not found.\n";
    }
}

void removeTask(vector<Task> &taskList, const string &description) {
    auto it = remove_if(taskList.begin(), taskList.end(), [&](const Task &task) {
        return task.description == description;
    });

    if (it != taskList.end()) {
        taskList.erase(it, taskList.end());
        cout << "Task removed successfully.\n";
    } else {
        cout << "Task not found.\n";
    }
}
