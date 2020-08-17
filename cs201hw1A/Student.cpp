//
// Created by Bulut Gözübüyük on 3.04.2020.
//


#include "Student.h"

// Constructor
Student::Student(int id, std::string firstName, std::string lastName) {
    numberOfCourses = 0;
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

// Destructor
Student::~Student() {
}

/**
 * Overload operator =
 * @param other Student
 */
void Student::operator=(const Student &other) {
    if (&other != this) {
        numberOfCourses = other.numberOfCourses;
        firstName = other.firstName;
        lastName = other.lastName;
        id = other.id;
    }
}

/**
 * Overload equals operator
 * @param rhs other Student
 * @return bool
 */
bool Student::operator==(const Student &rhs) const {
    return id == rhs.id &&
           numberOfCourses == rhs.numberOfCourses &&
           firstName == rhs.firstName &&
           lastName == rhs.lastName;
}

/**
 * Overload cout operator
 * @param os
 * @param student
 * @return
 */
std::ostream &operator<<(std::ostream &os, const Student &student) {
    os << student.id << "        " << student.firstName << "\t"
       << student.lastName;
    return os;
}

bool Student::operator!=(const Student &rhs) const {
    return !(rhs == *this);
}

int Student::getId() const {
    return id;
}
