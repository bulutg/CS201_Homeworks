//
// Created by Bulut Gözübüyük on 9.05.2020.
//

#include "Team.h"


Team::Team(const string &name, const string &color) : name(name), color(color) {
    this->playerCount = 0;
    this->head = NULL;
}

Team::Team(const string &name, const string &color, int year) : name(name), color(color), year(year) {
    this->playerCount = 0;
    this->head = NULL;
}

//Team::Team() = default;

//Team::~Team() = default;

// Default Constructor
Team::Team() {
    this->playerCount = 0;
    this->year = 2000;
    this->head = NULL;
    this->name = "";
    this->color = "";
}

// Destructor
Team::~Team() {
    Node *current = head;

    while (current != NULL) {
        Node *toHoldNext = current->next;
        delete current;
        current = toHoldNext;
    }

    this->head = NULL;
    this->playerCount = 0;


}

/**
 * Copy Constructor
 * @param rhs
 */
Team::Team(const Team &rhs) {
    this->year = rhs.year;
    this->name = rhs.name;
    this->color = rhs.color;
    this->playerCount = rhs.playerCount;

    if (rhs.head == NULL) {
        this->head = NULL;
    } else {
        this->head = new Node;
        this->head->t = rhs.head->t;
        Node *tailPlayer = this->head;
        for (Node *cur = rhs.head->next; cur != NULL; cur = cur->next) {
            tailPlayer->next = new Node;
            tailPlayer = tailPlayer->next;
            tailPlayer->t = cur->t;
        }
        tailPlayer->next = NULL;
    }
}

/**
 * A method to find a player in a team
 * @param playerName
 * @return
 */
Team::Node *Team::findPlayer(string playerName) const {
    for (int i = 0; i < playerName.size(); ++i)
        playerName[i] = tolower(playerName[i]);

    if (this->playerCount > 0) {
        Node *current = this->head;
        while (current != NULL) {
            if (current->t.getName() == playerName)
                return current;
            current = current->next;
        }
    }
    return NULL;
}

/**
 * A method to add a player to team
 * @param pName
 * @param pPos
 */
void Team::addPlayer(string pName, string pPos) {
    for (int i = 0; i < pName.size(); ++i)
        pName[i] = tolower(pName[i]);

    if (findPlayer(pName) != NULL) {
        cout << "Player already exists\n";
        return;
    }

    if (playerCount == 0) {
        Node *pNode = new Node;
        pNode->t = Player(pName, pPos);
        pNode->next = NULL;
        this->head = pNode;
        this->playerCount++;
        cout << "Player " << pName << " added\n";
        return;
    }

    Node *pNode = new Node;
    pNode->next = this->head;
    pNode->t = Player(pName, pPos);
    this->head = pNode;
    this->playerCount++;
    cout << "Player " << pName << " added\n";
}

/**
 * A method to remove specified player
 * @param playerName
 */
void Team::removePlayer(string playerName) {
    for (int i = 0; i < playerName.size(); ++i)
        playerName[i] = tolower(playerName[i]);

    if (findPlayer(playerName) == NULL) {
        cout << "Player does not exist" << endl;
        return;
    } else {
        Node *cur = this->head;
        if ((cur->t.getName() == playerName)) {
            Node *hold = cur;
            head = head->next;
            this->playerCount--;
            delete hold;
            cout << "Player " << playerName << " removed\n";
            return;
        }
        while (cur->next != NULL) {
            if (cur->next->t.getName() == playerName) {
                Node *next = cur->next->next;
                this->playerCount--;
                delete cur->next;
                cur->next = next;
                cout << "Player " << playerName << " removed\n";
                return;
            } else {
                cur = cur->next;
            }
        }
    }
}

/**
 * A method to display all players in the team
 */
void Team::displayAllPlayers() const {
    Node *current = this->head;
    if (this->playerCount > 0) {
        while (current != NULL) {
            cout << current->t << endl;
            current = current->next;
        }
    } else {
        cout << "--EMPTY--\n";
    }
}
/**
 * Assignment operator
 * @param right
 * @return
 */
Team &Team::operator=(const Team &right) {
    if (this != &right) {
        this->name = right.name;
        this->playerCount = right.playerCount;
        this->year = right.year;
        this->color = right.color;

        if (this->head != NULL) {
            Node *current = this->head;
            while (current != NULL) {
                Node *hold = current;
                current = current->next;
                delete hold;
            }
        }

        this->head = NULL;
        this->head = right.head;

        if (head != NULL) {
            Node *current = head;
            Node *p = new Node;
            p->t = current->t;
            p->next = NULL;
            this->head = p;
            Node *tail = this->head;
            current = current->next;
            while (current != NULL) {
                Node *n = new Node;
                n->t = current->t;
                tail->next = n;
                tail = tail->next;
                current = current->next;
            }

            tail->next = NULL;
        }
    }
    return *this;
}

/**
 * Stream output generator
 * @param os
 * @param team
 * @return
 */
ostream &operator<<(ostream &os, const Team &team) {
    os << team.name << ", " << team.color << ", " << team.year;
    return os;
}

/**
 * Get name
 * @return
 */
const string &Team::getName() const {
    return name;
}

/**
 * Get color
 * @return
 */
const string &Team::getColor() const {
    return color;
}

/**
 * Get year
 * @return
 */
int Team::getYear() const {
    return year;
}

/**
 * Set name
 * @param nameToSet
 */
void Team::setName(const string &nameToSet) {
    Team::name = nameToSet;
}

/**
 * Set color
 * @param colorToSet
 */
void Team::setColor(const string &colorToSet) {
    Team::color = colorToSet;
}

/**
 * Set year
 * @param year
 */
void Team::setYear(int year) {
    Team::year = year;
}

bool Team::playerExists(string playerName) const {
    for (int i = 0; i < playerName.size(); ++i)
        playerName[i] = tolower(playerName[i]);

    bool exists = false;
    if (this->playerCount > 0) {
        Node *cur = this->head;

        while (cur != NULL) {
            if ((cur->t.getName() == playerName)) {
                return !exists;
            }
            cur = cur->next;
        }
    }
    return exists;
}

string Team::getPlayerPosition(string playerName) {
    if (playerExists(playerName)) {
        return findPlayer(playerName)->t.getPosition();
    }
    return NULL;
}

