//
// Created by Bulut Gözübüyük on 8.05.2020.
//

#include "SimpleTeam.h"

Team::Team(const string &name, const string &color) : name(name), color(color) {}

Team::Team(const string &name, const string &color, int year) : name(name), color(color), year(year) {}

Team::Team() = default;

Team::~Team() = default;

Team::Team ( const Team &rhs ){
    this->name = rhs.name;
    this->color = rhs.color;
    this->year = rhs.year;
}

Team& Team::operator=( const Team &rhs ){
    if (this != &rhs) {
        this->name = rhs.name;
        this->color = rhs.color;
        this->year = rhs.year;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Team &team) {
    os << team.name << ", " << team.color << ", " << team.year;
    return os;
}

const string &Team::getName() const {
    return name;
}

const string &Team::getColor() const {
    return color;
}

int Team::getYear() const {
    return year;
}

void Team::setName(const string &nameToSet) {
    Team::name = nameToSet;
}

void Team::setColor(const string &colorToSet) {
    Team::color = colorToSet;
}

void Team::setYear(int year) {
    Team::year = year;
}
