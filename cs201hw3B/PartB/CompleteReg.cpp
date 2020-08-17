//
// Created by Bulut Gözübüyük on 9.05.2020.
//

#include "CompleteReg.h"
#include <stdexcept>

//
// Created by Bulut Gözübüyük on 9.05.2020.

// Constructor
CompleteReg::CompleteReg() {
    this->teamCount = 0;
    this->head = NULL;
    cout << "constructor\n" << endl;
}

// Destructor
CompleteReg::~CompleteReg() {
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
void CompleteReg::addTeam(const string tName, const string tColor, const int tyear) {

    if (tyear < 1800 || tyear > 2020) {
        cout << "Invalid year\n";
        return;
    }

    string copyName = tName;

    for (int i = 0; i < copyName.size(); ++i)
        copyName[i] = tolower(copyName[i]);

    if (findTeam(copyName) != NULL) {
        cout << copyName << " team already exists\n";
        return;
    }

    if (teamCount == 0) {
        Node *pNode = new Node;
        pNode->t = Team(copyName, tColor, tyear);
        pNode->next = NULL;
        this->head = pNode;
        this->teamCount++;
        cout << head->t.getName() << " team added" << endl;
        return;
    }

    Node *p = new Node;
    p->next = this->head;
    p->t = Team(copyName, tColor, tyear);
    this->head = p;
    this->teamCount++;
    cout << head->t.getName() << " team added" << endl;
}

/**
 * A method to remove team from reg
 * @param teamName
 */
void CompleteReg::removeTeam(string teamName) {
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
 * A method to display all teams
 */
void CompleteReg::displayAllTeams() const {
    cout << "\n---------------\nDisplaying all teams\n---------------\n";
    Node *current = this->head;
    if (this->teamCount > 0) {
        while (current != NULL) {
            cout << current->t << endl;
            current = current->next;
        }
    } else {
        cout << "--EMPTY--\n";
    }
    cout << endl;
}

/**
 * A method to find a team
 * @param teamName
 * @return
 */
CompleteReg::Node *CompleteReg::findTeam(string teamName) const {
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

/**
 * Copy constructor
 * @param systemToCopy
 */
CompleteReg::CompleteReg(const CompleteReg &systemToCopy) : teamCount(systemToCopy.teamCount) {
    if (systemToCopy.head == NULL) {
        this->head = NULL;
    } else {
        this->head = new Node;
        this->head->t = systemToCopy.head->t;

        Node *newTeam = this->head;
        for (Node *cur = systemToCopy.head->next; cur != NULL; cur = cur->next) {
            newTeam->next = new Node;
            newTeam = newTeam->next;
            newTeam->t = cur->t;
        }
        newTeam->next = NULL;
    }
    cout << "copy constructor \n" << endl;
}

/**
 * Equality operator overload
 * @param right
 * @return
 */
CompleteReg &CompleteReg::operator=(const CompleteReg &right) {
    if (this != &right) {
        this->teamCount = right.teamCount;

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
 * A method to add player
 * @param tName
 * @param pName
 * @param pPosition
 */
void CompleteReg::addPlayer(string tName, string pName, string pPosition) {
    string copyName = tName;

    for (int i = 0; i < copyName.size(); ++i)
        copyName[i] = tolower(copyName[i]);

    if (findTeam(copyName) == NULL) {
        cout << " Team " << copyName << " not found" << endl;
        return;
    } else {
        Node *team = findTeam(copyName);
        team->t.addPlayer(pName, pPosition);
    }

}

/**
 * A method to remove player
 * @param teamName
 * @param playerName
 */
void CompleteReg::removePlayer(string teamName, string playerName) {
    string copyName = teamName;

    for (int i = 0; i < copyName.size(); ++i)
        copyName[i] = tolower(copyName[i]);

    if (findTeam(copyName) == NULL) {
        cout << " Team " << copyName << " does not exist" << endl;
        return;
    } else {
        Node *team = findTeam(copyName);
        team->t.removePlayer(playerName);
    }
}

/**
 * Show team details
 * @param teamName
 */
void CompleteReg::displayTeam(string teamName) const {
    string copyName = teamName;

    for (int i = 0; i < copyName.size(); ++i)
        copyName[i] = tolower(copyName[i]);

    if (findTeam(copyName) == NULL) {
        cout << "\nTeam " << copyName << endl;
        cout << "--EMPTY--" << endl;
    } else {
        Node *team = findTeam(copyName);
        cout << (team->t) << endl;
        team->t.displayAllPlayers();
    }
}

/**
 * Display player
 * @param playerName
 */
void CompleteReg::displayPlayer(const string playerName) const {
    string copyName = playerName;

    for (int i = 0; i < copyName.size(); ++i)
        copyName[i] = tolower(copyName[i]);

    bool exists = false;
    cout << "Player: " << copyName << endl;
    if (teamCount == 0) {
        cout << "--EMPTY--" << endl;
    } else {
        Node *cur = this->head;
        while (cur != NULL) {
            if (cur->t.playerExists(copyName)) {
                exists = true;
                cout << (cur->t.getPlayerPosition(copyName)) << ", " << cur->t << endl;
            }
            cur = cur->next;
        }
        if (!exists) cout << "--EMPTY--" << endl;
    }
}

/**
 * Subscript operator
 */
Team &CompleteReg::operator[](const int index) {
    Node *current = head;
    int n = index - 1;
    while (current != NULL && n-- > 0) {
        current = current->next;
    }
    if (current != NULL) {
        return current->t;
    } else throw out_of_range("invalid index");
}
