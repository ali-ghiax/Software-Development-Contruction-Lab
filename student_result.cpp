/*
 * Program : Student Result Calculator
 * Course  : Software Construction and Development Lab
 *
 * A simple menu-driven C++ program that reads a student's name,
 * roll number, and marks in three subjects, then calculates the
 * total, percentage, and letter grade.
 *
 * Compile : g++ -o student_result student_result.cpp
 * Run     : .\student_result.exe
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

const int SUBJECT_COUNT = 3;
const string SUBJECTS[SUBJECT_COUNT] = {
    "Programming",
    "Mathematics",
    "Communication Skills"
};

struct Student {
    string name;
    int rollNo;
    double marks[SUBJECT_COUNT];
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double calculateTotal(const Student& student) {
    double total = 0.0;
    for (int i = 0; i < SUBJECT_COUNT; i++) {
        total += student.marks[i];
    }
    return total;
}

double calculatePercentage(double total) {
    return (total / (SUBJECT_COUNT * 100.0)) * 100.0;
}

char calculateGrade(double percentage) {
    if (percentage >= 90.0) return 'A';
    if (percentage >= 80.0) return 'B';
    if (percentage >= 70.0) return 'C';
    if (percentage >= 60.0) return 'D';
    return 'F';
}

string gradeRemark(char grade) {
    switch (grade) {
        case 'A': return "Excellent";
        case 'B': return "Very Good";
        case 'C': return "Good";
        case 'D': return "Satisfactory";
        default:  return "Needs Improvement";
    }
}

bool readStudent(Student& student) {
    cout << "\n----- Enter Student Details -----\n";

    cout << "Name: ";
    clearInput();
    getline(cin, student.name);
    if (student.name.empty()) {
        cout << "Name cannot be empty.\n";
        return false;
    }

    cout << "Roll number: ";
    if (!(cin >> student.rollNo) || student.rollNo <= 0) {
        cout << "Please enter a valid roll number.\n";
        clearInput();
        return false;
    }

    for (int i = 0; i < SUBJECT_COUNT; i++) {
        cout << "Marks in " << SUBJECTS[i] << " (0-100): ";
        if (!(cin >> student.marks[i]) || student.marks[i] < 0 || student.marks[i] > 100) {
            cout << "Marks must be a number between 0 and 100.\n";
            clearInput();
            return false;
        }
    }

    return true;
}

void displayResult(const Student& student) {
    double total = calculateTotal(student);
    double percentage = calculatePercentage(total);
    char grade = calculateGrade(percentage);

    cout << fixed << setprecision(2);
    cout << "\n========== RESULT CARD ==========\n";
    cout << "Name        : " << student.name << "\n";
    cout << "Roll Number : " << student.rollNo << "\n";
    cout << "----------------------------------\n";

    for (int i = 0; i < SUBJECT_COUNT; i++) {
        cout << left << setw(24) << SUBJECTS[i]
             << ": " << student.marks[i] << "\n";
    }

    cout << "----------------------------------\n";
    cout << "Total       : " << total << " / " << (SUBJECT_COUNT * 100) << "\n";
    cout << "Percentage  : " << percentage << "%\n";
    cout << "Grade       : " << grade << " (" << gradeRemark(grade) << ")\n";
    cout << "==================================\n";
}

void showMenu() {
    cout << "\n===== Student Result Calculator =====\n";
    cout << "1. Calculate a student result\n";
    cout << "2. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice = 0;

    cout << "Welcome to the Student Result Calculator\n";

    do {
        showMenu();
        if (!(cin >> choice)) {
            cout << "Please enter 1 or 2.\n";
            clearInput();
            continue;
        }

        if (choice == 1) {
            Student student;
            if (readStudent(student)) {
                displayResult(student);
            }
        } else if (choice != 2) {
            cout << "Invalid option. Please choose 1 or 2.\n";
        }
    } while (choice != 2);

    cout << "\nProgram ended. Goodbye.\n";
    return 0;
}
