//
// Created by Bulut Gözübüyük on 8.05.2020.
//

#ifndef CS201HW3_SIMPLETEAM_H
#define CS201HW3_SIMPLETEAM_H

using namespace std;

#include <string>
#include <stdio.h>
#include <iostream>

class Team {
public:

    Team(const string &name, const string &color);

    virtual ~Team();

    Team ();

    Team ( const Team &rhs );

    Team(const string &name, const string &color, int year);

    Team& operator=( const Team &right );

    const string &getName() const;

    const string &getColor() const;

    void setName(const string &name);

    void setColor(const string &color);

    int getYear() const;

    void setYear(int year);

    friend ostream &operator<<(ostream &os, const Team &team);

private:
    string name;
    string color;
    int year;

};


#endif //CS201HW3_SIMPLETEAM_H
