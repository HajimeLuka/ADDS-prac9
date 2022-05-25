#ifndef PREFIXTOINFIX_H
#define PREFIXTOINFIX_H

#include <iostream>

class PrefixToInfix{

public:
    PrefixToInfix();

    bool isOperator(char x);

    void convert(std::string expression);

    void evaluate(std::string expression);

};

#endif