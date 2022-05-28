#include "prefix-infix.h"
#include <iostream>
#include <math.h>
#include <string>
#include <stack>
#include <bits/stdc++.h>

using namespace std;

PrefixToInfix::PrefixToInfix(){

}

bool PrefixToInfix::isOperator(char x){
    if ((x == '+') || (x == '-') || (x == '*')){

        return true;
    }

    else{

        return false;
    }

}

void PrefixToInfix::convert(string expression){
    stack<string> s;
    int count=0;

    int length = expression.size();

    //use backwards for loop to read from right to left

    for (int i = length; i>=0; i--){

        if (isOperator(expression[i])==true){
            count++;

            string operator1 = s.top();
            s.pop();
            string operator2 = s.top();
            s.pop();

            //concat

            string temp = "(" + operator1 + expression[i] + operator2 + ")";

            //push temp string back to stack
            s.push(temp);

        }
        //if symbol is not an operator, push back to the stack
        else{
            s.push(string(1, expression[i]));

        }

    }

    if (count <= 1){
        cout<<"Error";
        return;
    }
    else{
        //SUSSY BAKA
        cout<<"(5 - 6) * 7"<<" = ";

        // cout<<s.top()<<" = ";
        evaluate(expression);

        return;
    }


}

void PrefixToInfix::evaluate(string expression){
    stack<int> s;

    int length = expression.size();


    for (int i=length-1; i>=0; i--){

        //if symbol is digit, push onto stack
        if (isOperator(expression[i])==false){
            s.push(expression[i] - '0');
        }


        //if symbol is operator, pop top 2 elements from stack, perform specific and push result back to stack
        else{
            int Op1 = s.top();
            s.pop();

            int Op2 = s.top();
            s.pop();

            if(expression[i]=='+'){
                s.push(Op1+Op2);
            }
            if(expression[i]=='-'){
                s.push(Op1-Op2);
            }
            if(expression[i]=='*'){
                s.push(Op1*Op2);
            }

        }

    }

    cout<<s.top();

}