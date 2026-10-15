#include <iostream>
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

int main() {
    cout << "Student Task Tracker" << endl;
    addTask("Finish the Git workflow lab");
    return 0;
}
