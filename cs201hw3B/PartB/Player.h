//
// Created by Bulut Gözübüyük on 13.05.2020.
//

#ifndef CS201HW3B_PLAYER_H
#define CS201HW3B_PLAYER_H

#include <string>
#include <ostream>

using namespace std;

class Player {
public:
    Player(const string &name, const string &position);

    Player();

    virtual ~Player();

    const string &getName() const;

    const string &getPosition() const;

    void setName(const string &name);

    void setPosition(const string &position);

    Player& operator=( const Player &right );

    bool operator==(const Player &rhs) const;

    bool operator!=(const Player &rhs) const;

    friend ostream &operator<<(ostream &os, const Player &player);

private:
    string name;
    string position;
};


#endif //CS201HW3B_PLAYER_H
