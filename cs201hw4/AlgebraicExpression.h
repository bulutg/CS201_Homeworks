//
// Created by Bulut Gözübüyük on 20.05.2020.
//

#ifndef CS201HW4_ALGEBRAICEXPRESSION_H
#define CS201HW4_ALGEBRAICEXPRESSION_H

#include <iostream>

using namespace std;

string infix2prefix( const string exp );
string prefix2postfix( const string exp );
double evaluatePrefix( const string exp );
bool isOperator(char c);
int getPrec(char c);

#endif //CS201HW4_ALGEBRAICEXPRESSION_H
