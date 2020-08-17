#include <iostream>
#include "SimpleReg.h"

int main() {
    SimpleReg test;
    test.addTeam("1","Red",1900);
    test.addTeam("2","asdad",1926);
    test.addTeam("6","asdad",1926);
    test.removeTeam("6");
    cout << "asdasdasd\n";
    test.displayAllTeams();

    test.removeTeam("1");


    test.displayAllTeams();

    return 0;
}
