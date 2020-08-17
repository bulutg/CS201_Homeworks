#include "RegistrationSystem.h"

int main() {

    RegistrationSystem rs;

    rs.showAllStudents();
    cout << endl;

    rs.addStudent(2000, "Esra", "Kara");
    rs.addStudent(1000, "Mehmet", "Celik");
    rs.addStudent(4000, "Ahmet", "Akcay");
    rs.addStudent(3000, "Fatih", "Isler");
    rs.addStudent(4000, "Can", "Uzun");
    rs.addStudent(6000, "Can", "Uzun");
    rs.addStudent(5000, "Ali", "Akdere");
    rs.addStudent(7000, "Berrak", "Tosun");
    cout << endl;

    rs.showAllStudents();
    cout << endl;

    rs.deleteStudent(5000);
    rs.deleteStudent(5000);
    cout << endl;

    rs.showStudent(1000);
    rs.showStudent(3000);
    rs.showStudent(5000);
    cout << endl;

    rs.showAllStudents();
    cout << endl;

    rs.showStudent(7000);
    cout << endl;

    rs.deleteStudent(7000);
    cout << endl;

    rs.showStudent(3000);
    cout << endl;

    rs.showAllStudents();
    cout << endl;

    return 0;
}
