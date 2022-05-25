#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

#include "prefix-infix.h"
using namespace std;

int main(){
    string expression;
    int answer;
    int count = 0;

    //getline includes spaces in input
    getline(cin, expression);
    int length = expression.size();

    //remove spaces from expresion WORKS
   remove(expression.begin(), expression.end(), ' ');


    PrefixToInfix* prefix = new PrefixToInfix();

    prefix -> convert(expression);


}