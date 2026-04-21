# Calculator Program

This program emulates a calculator using a stack. It reads input from a file ("input.txt") and prints the output to another file ("output.txt").

## Classes and Structures
### Pair
- Contains pairs of type variable (char) and value (int).

### Calculator
- Initializes the calculator for the program.
#### Attributes:
- `expressionStack`: Stores the expression characters in a stack.
- `variables`: Stores the variable names and values.

#### Methods:
- `void readInput()`: Reads the input file.
- `int execute()`: Executes the expression and returns the result.
- `void writeOutput()`: Writes the result in the output file.

## Supported Operators and Variables
- Possible operators: + - * / %
- Possible variable names: letters from A to Z, only uppercase, followed by '=' and an integer value.

## Input Format
- In the input file, variable declarations come first, followed by a single left-handed expression that uses the variables, in parentheses.

## Error Handling
- Invalid operator.
- Invalid numerical values and/or variable names.
- Variable used in the expression is not defined.
- Division by zero.