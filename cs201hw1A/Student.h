//
// Created by Bulut Gözübüyük on 3.04.2020.
//

#ifndef CS201HW1_STUDENT_H
#define CS201HW1_STUDENT_H


#include <string>
#include <ostream>
#include <iostream>

class Student {

private:
    int id;
    int numberOfCourses;
    std::string firstName;
    std::string lastName;


public:
    ~Student();

    Student(int id = 0,
            std::string firstName = "",
            std::string lastName = "");

    void operator=(const Student &other);

    bool operator==(const Student &rhs) const;

    bool operator!=(const Student &rhs) const;

    int getId() const;

    friend std::ostream &operator<<(std::ostream &os, const Student &student);

};


#endif //CS201HW1_STUDENT_H
