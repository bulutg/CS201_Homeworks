//
// Created by Bulut Gözübüyük on 3.04.2020.
//

#ifndef CS201HW1_COURSE_H
#define CS201HW1_COURSE_H


#include <string>
#include <ostream>

class Course {

private:
    int id;
    std::string name;

public:
    Course(int id = 0,
           std::string name = "");

    ~Course();

    void operator=(const Course &other);

    int getID();

    bool operator==(const Course &rhs) const;

    bool operator!=(const Course &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Course &course);


};


#endif //CS201HW1_COURSE_H
