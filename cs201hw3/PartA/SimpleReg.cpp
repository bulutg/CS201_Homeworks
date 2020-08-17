//
// Created by Bulut Gözübüyük on 9.05.2020.
//

#include "SimpleReg.h"

// Constructor
SimpleReg::SimpleReg() {
    this->teamCount = 0;
    this->head = NULL;
}

// Destructor
SimpleReg::~SimpleReg() {
    Node *current = head;

    while (current != NULL) {
        Node *toHoldNext = current->next;
        delete current;
        current = toHoldNext;
    }

    this->head = NULL;
    this->teamCount = 0;

}

/**
 * A method to add a team
 * @param tName
 * @param tColor
 * @param tyear
 */
void SimpleReg::addTeam(const string tName, const string tColor, const int tyear) {

    if (tyear < 1800 || tyear > 2020) {
        cout << "Invalid year\n";
        return;
    }

    string copyName = tName;

    for (int i = 0; i < copyName.size(); ++i)
        copyName[i] = tolower(copyName[i]);

    if (findTeam(copyName) != NULL) {
        return;
    }

    if (teamCount == 0) {
        Node *p = new Node;
        p->t = Team(copyName, tColor, tyear);
        p->next = NULL;
        this->head = p;
        this->teamCount++;
        return;
    }

    Node *n = new Node;
    n->next = this->head;
    n->t = Team(copyName, tColor, tyear);
    this->head = n;
    this->teamCount++;
}

/**
 * Remove team
 * @param teamName
 */
void SimpleReg::removeTeam(string teamName) {
    for (int i = 0; i < teamName.size(); ++i)
        teamName[i] = tolower(teamName[i]);

    if (findTeam(teamName) == NULL) {
        cout << "Team does not exist" << endl;
        return;
    }
    Node *current = this->head;
    if ((current->t.getName() == teamName)) {
        Node *ptr = current;
        head = head->next;
        this->teamCount--;
        delete ptr;
        cout << teamName << " removed\n";
        return;
    }
    while (current->next != NULL) {
        if (current->next->t.getName() == teamName) {
            Node *next = current->next->next;
            this->teamCount--;
            delete current->next;
            current->next = next;
            cout << teamName << " removed\n";
            return;
        }
        current = current->next;
    }
}

/**
 * Display all teams
 */
void SimpleReg::displayAllTeams() const {
    Node *current = this->head;
    if (this->teamCount > 0) {
        while (current != NULL) {
            cout << current->t << endl;
            current = current->next;
        }
    }
    cout << "--EMPTY--\n";
}

/**
 * find team
 * @param teamName
 * @return
 */
SimpleReg::Node *SimpleReg::findTeam(string teamName) const {

    for (int i = 0; i < teamName.size(); ++i)
        teamName[i] = tolower(teamName[i]);
    if (this->teamCount > 0) {
        Node *current = this->head;
        while (current != NULL) {
            if (current->t.getName() == teamName)
                return current;
            current = current->next;
        }
    }
    return NULL;
}
