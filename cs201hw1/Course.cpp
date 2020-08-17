//
// Created by Bulut Gözübüyük on 3.04.2020.
//

#include "Course.h"

// Constructor
Course::Course(int id,
               std::string name) {
    this->id = id;
    this->name = name;
};

// Destructor
Course::~Course() {};

/**
 * Overload operator of assignment
 * @param other
 */
void Course::operator=(const Course &other) {
    if (&other != this) {
        this->id = other.id;
        this->name = other.name;
    }
};

/**
 * Overload equals operator
 * @param rhs
 * @return
 */
bool Course::operator==(const Course &rhs) const {
    return id == rhs.id &&
           name == rhs.name;
}

bool Course::operator!=(const Course &rhs) const {
    return !(rhs == *this);
}

int Course::getID() {
    return id;
};

std::ostream &operator<<(std::ostream &os, const Course &course) {
    os <<  course.id << "         " << course.name;
    return os;
}
