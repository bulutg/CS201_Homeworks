//
// Created by Bulut Gözübüyük on 3.04.2020.
//

#ifndef CS201HW1_STUDENT_H
#define CS201HW1_STUDENT_H


#include <string>
#include <ostream>
#include <iostream>
#include "Course.h"

class Student {

private:
    int id;
    int numberOfCourses;
    std::string firstName;
    std::string lastName;
    Course *courses;


public:
//    Student();

    ~Student();

//    Student(const Student &studentToCopy);

    Student(int id = 0,
            std::string firstName = "",
            std::string lastName = "");

    void operator=(const Student &other);

    void addCourse(int courseID,
                   std::string courseName);

    bool removeCourse(const int courseID);

    bool operator==(const Student &rhs) const;

    bool operator!=(const Student &rhs) const;

    int getId() const;

    Course *getCourses() const;

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    friend std::ostream &operator<<(std::ostream &os, const Student &student);

    int isCourseExists(const int courseID);


};


#endif //CS201HW1_STUDENT_H
