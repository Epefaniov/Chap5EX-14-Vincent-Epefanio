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
#include <fstream>
#include <string>
#include <limits> // For numeric_limits

using namespace std;

int main() {
    ifstream inputFile("LineUp.txt");

    if (!inputFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string studentName;
    string frontStudent, backStudent;
    int numStudents = 0;

    // Read names from the file until EOF
    while (getline(inputFile, studentName)) {
        numStudents++;
        if (numStudents == 1) {
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

    inputFile.close();

    if (numStudents == 0) {
        cout << "No students found in the file." << endl;
    } else {
        cout << "The student at the front of the line is: " << frontStudent << endl;
        cout << "The student at the end of the line is: " << backStudent << endl;
    }

    return 0;
}


