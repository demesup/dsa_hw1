#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class Pair {
public:
    char variable;
    int value;

    Pair(char var, int val) : variable(var), value(val) {}

    void print() {
        cout << variable << "=" << value << endl;

    }
};

class Calculator {
private:
    stack<char> expressionStack;
    vector<Pair> variables;

public:

    void readInput(const string &filename) {
        ifstream inputFile(filename);
        if (!inputFile.is_open()) {
            cerr << "Error opening input file\n";
            return;
        }

        string line;
        while (getline(inputFile, line)) {
            if (!line.empty()) {
                if (line.find('=') != string::npos) {
                    char var;
                    int val;
                    auto equalSignPos = line.find('=');

                    var = line.at(equalSignPos - 1);
                    string str = line.substr(equalSignPos + 1, line.length());
                    try {
                        val = stol(str);
                        cout << "var: " << var << ", val: " << val << endl;

                    } catch (const exception &e) {
                        cerr << "Invalid input, should be a number: " << str << endl;
                        exit(1);
                    }

                    Pair pair(var, val);
                    variables.emplace_back(pair);
                } else {
                    for (char c: line) {
                        expressionStack.push(c);
                    }
                }
            }
        }
        cout << endl;

        inputFile.close();
    }

    void printVariables() {
        for (auto &variable: variables) {
            variable.print();
        }
    }


    void printExpression() {
        stack<char> expressions = expressionStack;

        while (!expressions.empty()) {
            cout << expressions.top() << endl;
            expressions.pop();
        }
    }


    int calculate(char op, int operand1, int operand2) const {
        cout << operand1 << op << operand2 << endl;

        if (!isOperator(op)) {
            string s(1, op);
            returnError("Invalid operator " + s);
        } else {
            switch (op) {
                case '+':
                    return operand1 + operand2;
                case '-':
                    return operand1 - operand2;
                case '*':
                    return operand1 * operand2;
                case '/':
                    checkDivisionByZero(operand2);
                    return operand1 / operand2;
                case '%':
                    checkDivisionByZero(operand2);
                    return operand1 % operand2;
                default:
                    returnError("Not implemented");
            }
        }
    }

    template<typename T>
    void printStack(stack<T> stack1) {
        stack<T> aux = stack1;
        while (!aux.empty()) {
            cout << aux.top() << " ";
            aux.pop();
        }

    }

    int execute() {
        if (expressionStack.empty()) {
            returnError("Error: No expression to evaluate.");
        }

        stack<int> operandStack;
        stack<char> operatorStack;


        while (!expressionStack.empty()) {

            char c = expressionStack.top();
            expressionStack.pop();

            if (c == '(') {
                while (!operatorStack.empty()) {
                    char op = operatorStack.top();
                    operatorStack.pop();

                    if (op == ')') {
                        break;
                    }

                    int operand1 = operandStack.top();
                    operandStack.pop();

                    int operand2 = operandStack.top();
                    operandStack.pop();

                    int calc = calculate(op, operand1, operand2);
                    operandStack.push(calc);

                    cout << "Result: " << calc << endl;

                }
            } else if (c >= 'A' && c <= 'Z') {
                operandStack.push(findVariableValue(c));
            } else if (c == ')' || isOperator(c)) {
                operatorStack.push(c);
            } else {
                returnError("Not implemented");
            }


        }

        return operandStack.top();
    }


    static void returnError(const string &error) {
        cerr << error << endl;
        exit(1);
    }

    void checkDivisionByZero(int denominator) const {
        if (denominator == 0) {
            returnError("Error: Division by zero.");
        }
    }


    void checkInvalidOperator(char op) const {
        if (!isOperator(op)) {
            returnError("Error: Invalid operator.");
        }
    }


    char pop() {
        char c = expressionStack.top();
        expressionStack.pop();
        return c;
    }

    void writeOutput(const string &filename, int result) {
        cout << "Writting..." << endl;
        ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            returnError("Error opening output file");
        }
        outputFile << "Result=" << result << endl;
        outputFile.close();
    }

private:


    static bool isOperator(const char &c) {
        return c == '*' || c == '+' || c == '-' || c == '/' || c == '%';
    }


    int findVariableValue(char varName) {
        for (Pair pair: variables) {
            if (pair.variable == varName) return pair.value;
        }
        string s(1, varName);
        returnError("Variable is not defined: " + s);
        return -1;
    }
};

int main() {
    Calculator calculator;
    calculator.readInput("1.txt");
    int result = calculator.execute();
    calculator.writeOutput("output.txt", result);
    return 0;
}
