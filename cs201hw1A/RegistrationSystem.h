//
// Created by Bulut Gözübüyük on 3.04.2020.
//

#ifndef CS201HW1_REGISTRATIONSYSTEM_H
#define CS201HW1_REGISTRATIONSYSTEM_H

#include <string>
#include <iostream>
#include "Student.h"

using namespace std;

class RegistrationSystem {

private:
    Student *students;
    int numberOfStudents;

public:
    RegistrationSystem();

    ~RegistrationSystem();

    void addStudent(const int studentId, const string firstName, const string lastName);

    void deleteStudent(const int studentId);

    void addCourse(const int studentId, const int courseId, const string courseName);

    void withdrawCourse(const int studentId, const int courseId);

    void cancelCourse(const int courseId);

    void showStudent(const int studentId);

    void showCourse(const int courseId);

    void showAllStudents();

    int isStudentExists(const int studentId);

};


#endif //CS201HW1_REGISTRATIONSYSTEM_H
