#include <iostream>
#include <string>
using namespace std;

struct Task {
    int id;
    string title;
    bool done;
};

int main() {
    Task sample;
    sample.id = 1;
    sample.title = "Finish the Git workflow lab";
    sample.done = false;

    cout << "Student Task Tracker" << endl;
    cout << sample.id << ". " << sample.title << endl;
    return 0;
}
