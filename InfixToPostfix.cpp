/*
Algorithm: Infix to Postfix Conversion

Create an empty stack for operators.

Initialize an empty string for the postfix expression.

Iterate through each character in the infix expression from left to right.

For each character:

If it's an operand (a digit or letter), add it to the postfix expression.
If it's an opening parenthesis '(', push it onto the stack.
If it's a closing parenthesis ')':
Pop operators from the stack and append them to the postfix expression until an opening parenthesis '(' is encountered.
Pop and discard the opening parenthesis from the stack.
If it's an operator (+, -, *, /, ^):
While the stack is not empty and the top operator has higher or equal precedence compared to the current operator, pop the top operator and append it to the postfix expression.
Push the current operator onto the stack.
After processing all characters in the infix expression, pop any remaining operators from the stack and append them to the postfix expression.

The resulting postfix expression is the desired output

*/

#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix = "";
    
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Output operands directly to postfix
        } else if (c == '(') {
            operatorStack.push(c);
        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop(); // Remove the '('
            }
        } else if (isOperator(c)) {
            while (!operatorStack.empty() && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack to postfix
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}

/*

Infix expression "3 + 5 * 2 ^ 4 / (1 + 1)" 
postfix expression "3524^*11+/".

*/
