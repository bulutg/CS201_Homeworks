#include "AlgebraicExpression.h"

int main() {
    cout << infix2prefix("((1+2)*(3+4))") << endl;
    cout << prefix2postfix(infix2prefix("((1+2)*(3+4))")) << endl;
    cout << infix2prefix("4/(((4+5)+2)*8)") << endl;
    cout << evaluatePrefix(infix2prefix("4/(((4+5)+2)*8)/2")) << endl;
    cout << evaluatePrefix(infix2prefix("((8+2)*5)/5/5")) << endl;
    cout << evaluatePrefix(infix2prefix("4/(((4+5)+2)*8)/2")) << endl;
    cout << "--------------\n";
    return 0;
}

