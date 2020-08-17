//
// Created by Bulut Gözübüyük on 9.05.2020.
//

#ifndef CS201HW3B_TEAM_H
#define CS201HW3B_TEAM_H

#include <string>
#include <stdio.h>
#include <iostream>
#include "Player.h"

using namespace std;

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

    void addPlayer( const string pName, const string pPos);
    void removePlayer( string playerName );
    void displayAllPlayers() const;

    bool playerExists(string playerName) const;
    string getPlayerPosition(string playerName);


private:
    string name;
    string color;
    int year;

    struct Node {
        Player t;
        Node* next;
    };

    Node *head;
    int playerCount;
    Node* findPlayer(string playerName) const;
};


#endif //CS201HW3B_TEAM_H
