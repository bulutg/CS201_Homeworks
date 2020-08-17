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
 * A method to add student to students array
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

    // Create the new student using parameters passed
    Student studentToAdd(studentId, firstName, lastName);

    // create new array if there is not
    if (numberOfStudents == 0) {
        numberOfStudents++;

        students = new Student[numberOfStudents];

        students[numberOfStudents - 1] = studentToAdd;
    } else {
        // warning if student already exists
        if (isStudentExists(studentId) > -1) {
            cout << "Student " << studentId << " already exists" << endl;
            return;
        }

        // extended array
        Student *temp = new Student[numberOfStudents + 1];

        bool inserted = false;
        int pos = -1;

        // calculate position to where to be inserted
        for (int i = 0; i < numberOfStudents; i++) {
            if (studentId < students[i].getId()) {
                pos = i;
                break;
            } else if (i == numberOfStudents - 1) pos = numberOfStudents;
        }

        // fill array
        for (int i = 0; i < numberOfStudents; i++)
            temp[i] = students[i];

        for (int i = numberOfStudents; i > pos; i--)
            temp[i] = students[i - 1];

        temp[pos] = studentToAdd;

        // free memory
        delete[] students;
        students = NULL;

        // create extended array
        numberOfStudents++;
        students = new Student[numberOfStudents];

        // copy array
        for (int i = 0; i < numberOfStudents; i++) students[i] = temp[i];

        // free memory
        delete[] temp;
    }

    cout << "Student " << studentId << " has been added" << endl;
};

/**
 * A method to delete student with provided id
 * @param studentId
 */
void RegistrationSystem::deleteStudent(const int studentId) {
    if (numberOfStudents > 0) {
        int index = isStudentExists(studentId);

        if (index > -1) {
            // delete array if there is no student
            if (numberOfStudents == 1) {
                numberOfStudents--;
                delete[] students;
                students = NULL;
                cout << "Student " << studentId << " has been deleted" << endl;
                return;
            }

            // copy array
            Student *temp = new Student[numberOfStudents];
            for (int i = 0; i < numberOfStudents; i++) {
                temp[i] = students[i];
            }

            // free memory
            delete[] students;
            students = NULL;

            // create new array
            numberOfStudents -= 1;
            students = new Student[numberOfStudents];

            // fill array
            for (int i = 0; i < index; i++)
                students[i] = temp[i];

            for (int i = index + 1; i < numberOfStudents + 1; i++)
                students[i - 1] = temp[i];

            // free memory
            delete[] temp;

            cout << "Student " << studentId << " has been deleted" << endl;

            return;
        }

        cout << "Student " << studentId << " does not exist" << endl;
    }

};

/**
 * A method to add course to a student
 * @param studentId
 * @param courseId
 * @param courseName
 */
void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName) {

    for (int i = 0; i < numberOfStudents; i++) {
        if (students[i].getId() == studentId) {
            students[i].addCourse(courseId, courseName);
            return;
        }
    }

};

/**
 * A method to witdraw course for a student
 * @param studentId
 * @param courseId
 */
void RegistrationSystem::withdrawCourse(const int studentId, const int courseId) {
    if (numberOfStudents > 0) {

        int index = isStudentExists(studentId);

        if (index > -1) {

            if (students[index].removeCourse(courseId))
                cout << "Student " << studentId << " has been withdrawn from course " << courseId << endl;
            else cout << "Student " << studentId << " is not enrolled in course " << courseId << endl;

            return;
        }

    }

    cout << "Student " << studentId << " does not exist" << endl;

};

/**
 * A method to delete all courses with specified id
 * @param courseId
 */
void RegistrationSystem::cancelCourse(const int courseId) {
    bool exists = false;
    if (numberOfStudents > 0)
        for (int i = 0; i < numberOfStudents; i++)
            if (students[i].removeCourse(courseId)) exists = true;

    if (exists)
        cout << "Course " << courseId << " has been cancelled" << endl;
    else
        cout << "Course " << courseId << " does not exist" << endl;

};

/**
 * A method to show details of a student with specified id
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
 * A method to show course in a detailed form
 * @param courseId
 */
void RegistrationSystem::showCourse(const int courseId) {
    bool exists = false;
    int index = -1;
    if (numberOfStudents > 0)
        for (int i = 0; i < numberOfStudents; i++) {
            index = students[i].isCourseExists(courseId);
            if (index > -1) {
                if (!exists){
                    cout << "Course id\tCourse Name" << endl;
                    cout << students[i].getCourses()[index] << endl;
                    cout << "\tStudent id\tFirst name\tLast Name" << std::endl;
                }

                cout << "\t" << students[i].getId() << "        " << students[i].getFirstName() << "\t" << students[i].getLastName() << endl;
                exists = true;
            }
        }
    if (!exists)
        cout << "Course " << courseId << " does not exist" << endl;
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
            if (students[i].getId() == studentId)
                return i;
        }
    }
    return -1;
}