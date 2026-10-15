#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

struct Task {
    int id;
    string title;
    bool done;
};

vector<Task> tasks;
int nextId = 1;

void addTask(const string& title) {
    Task task;
    task.id = nextId++;
    task.title = title;
    task.done = false;
    tasks.push_back(task);
    cout << "Added task " << task.id << ": " << task.title << endl;
}

void listTasks() {
    if (tasks.empty()) {
        cout << "No tasks yet." << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (const Task& task : tasks) {
        cout << task.id << ". " << task.title;
        if (task.done) {
            cout << " [done]";
        }
        cout << endl;
    }
}

int main() {
    int choice = 0;

    cout << "Student Task Tracker" << endl;

    do {
        cout << "\n1. Add a task" << endl;
        cout << "2. List tasks" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Please enter 1, 2, or 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 1) {
            string title;
            cout << "Task title: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, title);
            if (title.empty()) {
                cout << "Title cannot be empty." << endl;
            } else {
                addTask(title);
            }
        } else if (choice == 2) {
            listTasks();
        } else if (choice != 3) {
            cout << "Invalid option. Please choose 1, 2, or 3." << endl;
        }
    } while (choice != 3);

    cout << "Goodbye." << endl;
    return 0;
}
