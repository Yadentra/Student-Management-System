#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string department;
};

void addStudent() {
    ofstream file("students.txt", ios::app);
    Student student;
    cout << "Enter Student ID: ";
    cin >> student.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Age: ";
    cin >> student.age;
    cout << "Enter Department: ";
    cin.ignore();
    getline(cin, student.department);
    file << student.id << " " << student.name << " " << student.age << " " << student.department << endl;
    file.close();
    cout << "Student added successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");
    Student student;
    cout << "\n--- Student Records ---\n";
    while (file >> student.id >> student.name >> student.age >> student.department) {
        cout << "ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << ", Department: " << student.department << endl;
    }
    file.close();
}

void searchStudent() {
    ifstream file("students.txt");
    int id;
    cout << "Enter Student ID to search: ";
    cin >> id;
    Student student;
    bool found = false;
    while (file >> student.id >> student.name >> student.age >> student.department) {
        if (student.id == id) {
            cout << "Student Found: ID: " << student.id << ", Name: " << student.name << ", Age: " << student.age << ", Department: " << student.department << endl;
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "Student not found!\n";
}

void deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    int id;
    cout << "Enter Student ID to delete: ";
    cin >> id;
    Student student;
    bool found = false;
    while (file >> student.id >> student.name >> student.age >> student.department) {
        if (student.id == id) {
            cout << "Deleting Student ID: " << student.id << endl;
            found = true;
        } else {
            temp << student.id << " " << student.name << " " << student.age << " " << student.department << endl;
        }
    }
    file.close();
    temp.close();
    remove("students.txt");
    rename("temp.txt", "students.txt");
    if (!found) cout << "Student not found!\n";
    else cout << "Student deleted successfully!\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}