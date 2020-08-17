#include "CompleteReg.h"


int main()
{
    Team t1;
    t1.setColor("sari");
    t1.setName("galatasaray");
    t1.setYear(1903);
    t1.displayAllPlayers();
    t1.removePlayer("berkay");
    t1.addPlayer("ege", "forvet");
    t1.displayAllPlayers();
    cout << "/////" << endl;
    Team t2;
    t2 = t1;
    t2.displayAllPlayers();
    t2.addPlayer("berkay", "k");
    t1.displayAllPlayers();
    t2.displayAllPlayers();
    cout << endl;
    Team t3(t2);
    t3.displayAllPlayers();
    cout << endl;
    Team t4(t1);
    t4.displayAllPlayers();
    t4 = t2;
    t4.displayAllPlayers();
    t4.removePlayer("Ege");
    t4.displayAllPlayers();
    t4.removePlayer("bERKAY");

    cout << endl;
    t3 = t1;
    t3.displayAllPlayers();

    cout << "\n\n\n\nSystem part \n";
    CompleteReg c;
    c.removePlayer("galata", "ege");
    c.removeTeam("fener");
    c.addTeam("galata", "sari", 1900);
    c.addTeam("Galata", "sari", 1900);
    c.addTeam("gAlata", "sari", 1900);
    c.addTeam("gaLata", "sari", 1900);
    c.addTeam("galAta", "sari", 1900);
    c.addTeam("galaTA", "sari", 1900);
    c.addTeam("gAlAtA", "sari", 1900);
    c.addTeam("GaLaTa", "sari", 1900);
    c.addTeam("galata", "sari", 1900);
    CompleteReg c1(c);
    c.addTeam("gaLata", "kirmizi", 1900);
    c.addTeam("fener", "sari",1907);
    c.addTeam("besik", "siyah", 1903);
    c.displayAllTeams();
    cout << endl;
    c.addPlayer("galata", "furkan", "defans");
    c.displayTeam("galata");
    c.removePlayer("galata", "ege");
    c.removePlayer("galata", "furkan");
    cout << endl;
    c1.displayAllTeams();
    cout << c[3].getColor() << "\n" << endl;
    CompleteReg c2(c);
    c2.displayAllTeams();
    c2[1].addPlayer("ege", "forvet");
    c2[1].addPlayer("berkay", "defans");
    c2[1].addPlayer("eGe", "defans");
    cout << endl;
    c2.displayTeam("besik");
    cout << endl;
    c.displayTeam("besik");
    cout << endl;
    c1 = c2;
    c1.displayTeam("besik");
    CompleteReg c3(c2);
    c3.displayAllTeams();
    c3.removeTeam("galata");
    c3.removeTeam("fener");
    c3.removeTeam("besik");
    c3.removePlayer("galata", "ege");
    c3.removeTeam("galata");
    c3.removeTeam("trabzon");
    c2.removeTeam("besik");
    c2.removeTeam("fener");
    c2.removeTeam("galata");
    cout << "\n\n\n\n";
    c.displayAllTeams();
    c[1].addPlayer("emir" , "forvet");
    c[2].addPlayer("emir" , "defans");
    c.displayPlayer("emir");
    c.displayPlayer("asd");


    CompleteReg re;
    re.addTeam("galata", "sari", 1799);
    re.addTeam("Galata", "sari", 1900);
    re.addTeam("gAlata", "sari", 1900);
    re.addTeam("gaLata", "sari", 1900);
    re.addTeam("gaLAta", "sari", 1900);
    re.addTeam("gaLaTa", "sari", 1900);
    re.addTeam("gaLatA", "sari", 1900);
    re.addTeam("fener", "mavi", 1907);

    re.addPlayer("GALATA", "ege", "forvet");
    re.addPlayer("GALAta", "egE", "forvet");
    re.addPlayer("Fener","eGE", "forvet");
    re.addPlayer("fener", "furkan", "forvet");
    CompleteReg re1(re);
    re1.displayAllTeams();
    cout << endl;
    re.displayTeam("feNEr");
    cout << endl;
    re.removePlayer("GaLaTa", "furkan");
    re.displayPlayer("ege");
    re.removePlayer("GaLaTa", "EGE");
    re.removePlayer("fener", "EGE");
    re.removePlayer("fENEr", "ege");
    re.removePlayer("galaa", "ege");

    return 0;
}
