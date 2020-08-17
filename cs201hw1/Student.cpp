//
// Created by Bulut Gözübüyük on 3.04.2020.
//


#include "Student.h"

// Constructor
Student::Student(int id, std::string firstName, std::string lastName) {
    courses = NULL;
    numberOfCourses = 0;
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

// Destructor
Student::~Student() {
    if (numberOfCourses > 0) {
        delete[] courses;
    }
}

/**
 * Overload assignment operator
 * @param other
 */
void Student::operator=(const Student &other) {
    if (&other != this) {
        numberOfCourses = other.numberOfCourses;
        firstName = other.firstName;
        lastName = other.lastName;
        id = other.id;

        if (numberOfCourses > 0) {
            // free memory
            delete[] courses;
            courses = NULL;

            courses = new Course[numberOfCourses];

            for (int i = 0; i < numberOfCourses; ++i)
                courses[i] = other.courses[i];

        } else {
            courses = NULL;
            numberOfCourses = 0;
        }
    }
}

/**
 * A method to add course to sorted array
 * @param courseID
 * @param courseName
 */
void Student::addCourse(const int courseID, const std::string courseName) {
    Course courseToAdd(courseID, courseName);

    // create new array if there is no courses
    if (numberOfCourses == 0) {
        courses = new Course[++numberOfCourses];
        courses[numberOfCourses - 1] = courseToAdd;
    }
    else {
        // exit if course already exists
        if(isCourseExists(courseID) > -1) {
            std::cout << "Student " << this->id << " already enrolled in course " << courseID << std::endl;
            return;
        }

        // initialize temp array
        Course *temp = new Course[numberOfCourses];

        for (int i = 0; i < numberOfCourses; i++) {
            temp[i] = courses[i];
        }

        // free memory
        delete[] courses;
        courses = NULL;

        // extend array
        numberOfCourses++;
        courses = new Course[numberOfCourses];
        for (int i = 0; i < numberOfCourses - 1; i++)
            courses[i] = temp[i];

        courses[numberOfCourses - 1] = courseToAdd;
        // free memory
        delete[] temp;
    }

    std::cout << "Course " << courseID << " has been added to student " << this->id << std::endl;
}

/**
 * Overlaod equals operator
 * @param rhs
 * @return
 */
bool Student::operator==(const Student &rhs) const {
    return id == rhs.id &&
           numberOfCourses == rhs.numberOfCourses &&
           firstName == rhs.firstName &&
           lastName == rhs.lastName &&
           courses == rhs.courses;
}

/**
 * A method to remove course from student
 * @param courseID
 * @return
 */
bool Student::removeCourse(const int courseID) {
    if (numberOfCourses > 0) {
        int index = isCourseExists(courseID);

        if (index > -1) {

            // delete array to avoid memory leak
            if (numberOfCourses == 1) {
                numberOfCourses--;
                delete[] courses;
                courses = NULL;
                return true;
            }

            // create temp array
            Course *temp = new Course[numberOfCourses];
            for (int i = 0; i < numberOfCourses; i++)
                temp[i] = courses[i];

            // free the memory
            delete[] courses;
            courses = NULL;

            // create smaller array
            numberOfCourses--;
            courses = new Course[numberOfCourses];

            // copy to new array
            for (int i = 0; i < index; i++)
                courses[i] = temp[i];

            for (int i = index + 1; i < numberOfCourses + 1; i++)
                courses[i - 1] = temp[i];

            delete[] temp;

            return true;
        }
        return false;
    }
    return false;
}

/**
 * A method to check whether a course exist or not
 * @param courseID
 * @return
 */
int Student::isCourseExists(const int courseID) {
    for (int i = 0; i < numberOfCourses; i++) {
        if (courses[i].getID() == courseID) {
            return i;
        }
    }
    return -1;
}

bool Student::operator!=(const Student &rhs) const {
    return !(rhs == *this);
}

int Student::getId() const {
    return id;
}

Course *Student::getCourses() const {
    return courses;
}

const std::string &Student::getFirstName() const {
    return firstName;
}

const std::string &Student::getLastName() const {
    return lastName;
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
    if (student.numberOfCourses > 0) {
        os << std::endl << "\tCourse id\tCourse name" << std::endl;

        for (int i = 0; i < student.numberOfCourses; i++) {
            os << "\t" << student.courses[i] << std::endl;
        }
    }
    return os;
}