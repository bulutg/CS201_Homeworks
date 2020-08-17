//
// Created by Bulut Gözübüyük on 13.05.2020.
//

#include "Player.h"

// Constructor
Player::Player(const string &name, const string &position) : name(name), position(position) {}

// Default constructor

Player::Player() {}

// Default destructor
Player::~Player() {}

/**
 * Assignment operator overload
 * @param right
 * @return
 */
Player &Player::operator=(const Player &right) {
    if (this != &right) {
        this->name = right.name;
        this->position = right.position;
    }
    return *this;
}

/**
 *
 * @return Player Name
 */
const string &Player::getName() const {
    return name;
}

/**
 *
 * @return Player Position
 */
const string &Player::getPosition() const {
    return position;
}

/**
 * Set player name
 * @param name
 */
void Player::setName(const string &name) {
    Player::name = name;
}

/**
 * Set player position
 * @param position
 */
void Player::setPosition(const string &position) {
    Player::position = position;
}

/**
 * Equality operator overload
 * @param rhs
 * @return
 */
bool Player::operator==(const Player &rhs) const {
    return name == rhs.name &&
           position == rhs.position;
}

/**
 *
 * @param rhs
 * @return
 */
bool Player::operator!=(const Player &rhs) const {
    return !(rhs == *this);
}

/**
 * Stream output operator overload
 * @param os
 * @param player
 * @return
 */
ostream &operator<<(ostream &os, const Player &player) {
    os << "Position: " << player.position << ",name: " << player.name ;
    return os;
}



