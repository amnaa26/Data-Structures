/*
Q2. You are building an expression evaluator as part of a simple calculator application. Your
task is to implement

o infix_to_postfix
o Modify the infix_to_postfix algorithm to implement infix_to_prefix, include
comments where the code is modified.

Test with the given expressions: K+L-M*N+(O^P)*W/U/V*T+Q

*/

#include <iostream>
#include <string>
#include "stack.hpp"
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

bool isLeftAssociative(char op) {
    return (op != '^'); // All operators except '^' are left associative
}

/*
        INFIX_TO_POSTFIX CONVERSION
*/

string infix_to_postfix(string infix){
    Stack stack;
    string postfix = "";
    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];
        
        //if c is an operand then we add it to the string
        if(isalnum(c)){
            postfix += c;
        }

        //if c is "(" we push it into the stack
        else if(c == '('){
            stack.push(c);
        }

        //if c is ")" then we pop all the operators present in the stack till "(" is found
        else if(c == ')'){
            while(!stack.isEmpty() && stack.peek() != '('){
                postfix += stack.pop();
            }
             if(!stack.isEmpty())  //with the help of this line of code we are removing the ')' if stack is not empty
                stack.pop();

        }

        //if c is an operator
        else if(isOperator(c)){
            while(!stack.isEmpty() && precedence(stack.peek()) >= precedence(c)){
                if(precedence(c) == precedence(stack.peek()) && isLeftAssociative(c)){
                    postfix += stack.pop(); //pop if left associative
                } else postfix += stack.pop(); //always pop when higher precedence
            }

            stack.push(c);
        }
    }

    //now we are popping all the remaining operators in the stack when all alphanumeric values have been added to the string
    while(!stack.isEmpty()){
        postfix += stack.pop();
    }

    return postfix;
}



/*
        INFIX_TO_PREFIX CONVERSION
*/

//reversing string as it will be helpful to us in prefix conversion
string reverse_string(string str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    return str;
}


string infix_to_prefix(string infix){
    infix = reverse_string(infix);
    cout << "\nReversed Infix: " << infix << endl;

    //first step of reversing is done 
    //Now we have to swap '(' to ')' so that it can be completely reversed
    for(int i = 0; i < infix.length(); i++){
        if(infix[i] == '('){
            infix[i] = ')';
        }
        else if (infix[i] == ')'){
            infix[i] = '(';
        }
    }

    //we are converting the reversed infix expression to pstfix expression
    string postfix = infix_to_postfix(infix);
    cout << "\nPostfix: " << postfix << endl;


    //now we will reverse the postfix expression and the result which we will get is a prefix expression
    string prefix = reverse_string(postfix);
    cout << "\nPrefix: " << prefix << endl;
    return prefix;
}

int main(){
    string input = "K+L-M*N+(O^P)*W/U/V*T+Q";
    string postfix = infix_to_postfix(input);
    cout << "\nPostfix Expression: " << postfix << endl;
    string prefix = infix_to_prefix(input);
    cout << "Prefix Expression: " << prefix << endl;

    return 0;
    
}


