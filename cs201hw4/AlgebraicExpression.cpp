//
// Created by Bulut Gözübüyük on 16.05.2020.
//

#include "Stack.cpp"
#include "AlgebraicExpression.h"

using namespace std;

/**
 * A method to check char is an operator or not
 * @param c
 * @return
 */
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

/**
 * A method to get precedence of operator
 * @param c
 * @return
 */
int getPrec(char c) {
    if( c == '+' || c == '-' ) return 1;
    if( c == '*' || c == '/' ) return 2;
    if( c == '(' || c == ')' ) return 3;
    return 0;
}

/**
 * A method that converts infix expression to prefix expression
 * @param exp infix expression
 * @return prefix expression
 */
string infix2prefix(string exp) {

    if (exp.empty()) return "";

    Stack<char> opStack;
    Stack<char> prefix;
    char chr;

    string result;

    for (int i = exp.size() - 1; i >= 0 ; i--) {
        chr = exp[i];
        if (isOperator(chr)){
            if (chr == '('){
                while (opStack.peek() != ')'){
                    prefix.push(opStack.peek());
                    opStack.pop();
                }
                opStack.pop();
            }
            else {
                while (!opStack.isEmpty() && opStack.peek() != ')' && getPrec(opStack.peek()) > getPrec(chr) ) {
                    prefix.push(opStack.peek());
                    opStack.pop();
                }
                opStack.push(chr);
            }
        }
        else prefix.push(chr);
    }

    //Put remaining operators
    while (!opStack.isEmpty()){
        prefix.push(opStack.peek());
        opStack.pop();
    }

    // Convert to string
    while (!prefix.isEmpty()){
        result += prefix.peek();
        prefix.pop();
    }
    return result;
}

double evaluatePrefix(string exp) {
    Stack<double> stack;

    for (int i = exp.size() - 1; i >= 0 ; i--) {
        if (!isOperator(exp[i]))
            stack.push(exp[i] - '0');
        else{
            double item1 = stack.peek();
            stack.pop();
            double item2 = stack.peek();
            stack.pop();
            if (exp[i] == '+')
                stack.push(item1 + item2);
            else if (exp[i] == '-')
                stack.push(item1 - item2);
            else if (exp[i] == '*')
                stack.push(item1 * item2);
            else if (exp[i] == '/')
                stack.push(item1 / item2);
        }
    }
    return stack.peek();
}


