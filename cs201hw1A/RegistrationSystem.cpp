//
// Created by Bulut Gözübüyük on 3.04.2020.
//

#include "RegistrationSystem.h"

// Constructor
RegistrationSystem::RegistrationSystem() {
    students = NULL;
    numberOfStudents = 0;
};

// Destructor
RegistrationSystem::~RegistrationSystem() {
    if (numberOfStudents > 0) {
        delete[] students;
    }
};

/**
 * A method to add student
 * @param studentId
 * @param firstName
 * @param lastName
 */
void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName) {

    if (studentId < 1) {
        cout << "Please enter valid id" << endl;
        return;
    }

    if(firstName.empty() || lastName.empty()){
        cout << "Please enter valid first name and surname" << endl;
        return;
    }

    // Create new student
    Student studentToAdd(studentId, firstName, lastName);

    if (numberOfStudents == 0) {
        numberOfStudents++;

        students = new Student[numberOfStudents];

        students[numberOfStudents - 1] = studentToAdd;
    } else {
        if (isStudentExists(studentId) > -1) {
            cout << "Student " << studentId << " already exists" << endl;
            return;
        }

        // extend array size
        Student *temp = new Student[numberOfStudents + 1];

        bool inserted = false;
        int pos = -1;

        // Get correct index to add correct place
        for (int i = 0; i < numberOfStudents; i++) {
            if (studentId < students[i].getId()) {
                pos = i;
                break;
            } else if (i == numberOfStudents - 1) pos = numberOfStudents;
        }

        // Copy array
        for (int i = 0; i < numberOfStudents; i++)
            temp[i] = students[i];
        for (int i = numberOfStudents; i > pos; i--)
            temp[i] = students[i - 1];

        temp[pos] = studentToAdd;

        // free students
        delete[] students;
        students = NULL;

        numberOfStudents++;
        students = new Student[numberOfStudents];

        for (int i = 0; i < numberOfStudents; i++) students[i] = temp[i];

        // free temp array memory
        delete[] temp;
    }

    cout << "Student " << studentId << " has been added" << endl;
};

/**
 * A method to delete specified student
 * @param studentId
 */
void RegistrationSystem::deleteStudent(const int studentId) {
    if (numberOfStudents > 0) {
        int index = isStudentExists(studentId);

        if (index > -1) {

            // if it is the last one, delete array
            if (numberOfStudents == 1) {
                numberOfStudents--;
                delete[] students;
                students = NULL;
                return;
            }

            Student *temp = new Student[numberOfStudents];
            for (int i = 0; i < numberOfStudents; i++) {
                temp[i] = students[i];
            }

            // free memory
            delete[] students;
            students = NULL;

            numberOfStudents -= 1;

            // New array
            students = new Student[numberOfStudents];

            // Copy array
            for (int i = 0; i < index; i++) {
                students[i] = temp[i];
            }

            for (int i = index + 1; i < numberOfStudents + 1; i++) {
                students[i - 1] = temp[i];
            }

            // free memory
            delete[] temp;

            cout << "Student " << studentId << " has been deleted" << endl;

            return;
        }

        cout << "Student " << studentId << " does not exist" << endl;
    }

};

/**
 * A method to show specified student
 * @param studentId
 */
void RegistrationSystem::showStudent(const int studentId) {
    if (numberOfStudents > 0) {
        int index = isStudentExists(studentId);

        if (index > -1) {
            cout << "Student id\tFirst name\tLast name" << endl;
            cout << students[index] << endl;
            return;
        }
    }
    cout << "Student " << studentId << " does not exist" << endl;
};

/**
 * A method to show all students
 */
void RegistrationSystem::showAllStudents() {
    if (numberOfStudents > 0) {
        cout << "Student id\tFirst name\tLast name" << endl;
        for (int i = 0; i < numberOfStudents; i++) {
            cout << students[i] << endl;
        }
    } else cout << "There are no students in the system" << endl;

};

/**
 * A method to check whether a student exists or not
 * @param studentId
 * @return
 */
int RegistrationSystem::isStudentExists(const int studentId) {
    if (numberOfStudents > 0) {
        for (int i = 0; i < numberOfStudents; i++) {
            if (students[i].getId() == studentId) {
                return i;
            }
        }
    }
    return -1;
}