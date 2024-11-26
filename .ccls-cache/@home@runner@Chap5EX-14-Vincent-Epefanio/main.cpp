/*
    Assignment: Chapter 5 Excercise 25

    Programmer: Vincent Epefanio

    Date: 11/25/2024

    Reqirements: A teacher has asked all her students to line up according to their first name.

    For example, in one class Amy will be at the front of the line, and Yolanda will be at the end.

    Write a program that prompts the user to enter the number of students in the class, then loops to read that many names.

    Once all the names have been read, it reports which student would be at the front of the line and

    which one would be at the end of the line. You may assume that no two students have the same name.

    Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.



    Using Files—Student Line Up -Create a second branch for this project and modify your program to do the following:
    Create a new branch in your Exercise 14 project that modifies the Student Line Up program described in Programming Challenge 14 so it reads the student names from the file LineUp.txt. The program should read names from the file until there is no more data to read.


*/


#include <iostream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

int main() {
    int numStudents;

    // Input and validation for number of students
    cout << "Enter the number of students in the class (between 1 and 25): ";
    while (true) {
        cin >> numStudents;
        if (numStudents >= 1 && numStudents <= 25) {
            break;
        } else {
            cout << "Number of students must be between 1 and 25. Please enter again: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore incorrect input
        }
    }

    string studentName;
    string firstName, lastName;
    string frontStudent, backStudent;

    cout << "Enter the names of the students:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> studentName;

        if (i == 0) {
            frontStudent = studentName;
            backStudent = studentName;
        } else {
            if (studentName < frontStudent) {
                frontStudent = studentName;
            }
            if (studentName > backStudent) {
                backStudent = studentName;
            }
        }
    }

    cout << "The student at the front of the line is: " << frontStudent << endl;
    cout << "The student at the end of the line is: " << backStudent << endl;

    return 0;
}
