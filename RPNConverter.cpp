#include "RPNConverter.hpp"

RPNConverter::RPNConverter() {
    operatorDictionary = {
        {'=',std::make_tuple(4, "Right")},
        {'^',std::make_tuple(4, "Right")},
        {'*',std::make_tuple(3, "Left")},
        {'/',std::make_tuple(3, "Left")},
        {'+',std::make_tuple(2, "Left")},
        {'-',std::make_tuple(2, "Left")}
    };
}

std::vector<std::string> RPNConverter::convertToRPN(std::string infixEq) {
    lastEqConverted = infixEq;
    
    //tokenize the equation by splitting it on its operators
    std::vector<std::string> tokenizedEq = tokenizeViaOperators(infixEq);

    //operator stack
    std::vector<std::string> operStack;

    std::vector<std::string> result;

    std::string lastTokenChecked;

    //for detecting unary negation of numbers
    bool isNeg = false;

    for (unsigned int i = 0; i < tokenizedEq.size(); ++i) {
        std::string token = tokenizedEq[i];
        const char* foundToken = std::find(std::begin(ops), std::end(ops), token[0]);
        if (isNumber(token)) {

            if (isNeg) {//if we have unary negation, make the number negative and go from there
                token.insert(0, "-");
                isNeg = false;
            }
            result.push_back(token);
        //if we find an operator we are looking for
        } else if (token.length() == 1 && foundToken != std::end(ops)) {

            //first, we check to see if it is a unary negation and set up the algorithm from there
            if (token == "-" && (lastTokenChecked == "" || foundToken != std::end(ops) || lastTokenChecked == "(")) {
                isNeg = true;
            } else {
                std::string o1 = token;
                std::string o2 = operStack[operStack.size() - 1];

                //while ()
            }
        }
    }

    return result;
}

//splits a string into a vector of strings based on a list of operators
std::vector<std::string> RPNConverter::tokenizeViaOperators(std::string eq) {

    //remove all white space from the equation 
    eq.erase(remove_if(eq.begin(), eq.end(), ::isspace), eq.end());

    std::string holder;//holds the current chunk of chars until we get an operator

    std::vector<std::string> tokenizedString;

    for (auto &c : eq) {
        const char* operCharFound = std::find(std::begin(ops), std::end(ops), c);

        //if char is not an operator, we add the character to the holder string
        if (operCharFound == std::end(ops)) 
            holder += c;
        else {
            //push back the holder string into the vector
            tokenizedString.push_back(holder);
            //convert the operator character to a string and push into the vector
            tokenizedString.push_back(std::string(1,c));
            //reset the holder string
            holder = "";
        } 
    }

    tokenizedString.push_back(holder);

    return tokenizedString;
}

int RPNConverter::indexOf(std::string str, std::string substr) {

    int str1Len = str.length();
    int str2Len = substr.length();

    for (unsigned int i = 0; i < str2Len - str1Len; ++i) {
        unsigned int j;
        for (j = 0; j < str1Len; ++j) if (substr[i + j] != str[j]) break;
        if (j == str1Len) return i;
    }
    return -1;
}

int RPNConverter::indexOf(std::string arr[], std::string str) {

}