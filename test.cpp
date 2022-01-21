#include <assert.h>
#include <string>
#include <vector>
#include <iostream>
#include "RPNConverter.hpp"

int main() {

    RPNConverter r;

    //----------------------------TEST tokenizeViaOperators------------------------
    std::string s = "37 = x + 2";//becomes a vector like ["37", "=", "x", "+", "2"]
    std::string testArr[] = {"37", "=", "x", "+", "2"};

    std::vector<std::string> testingVector = r.tokenizeViaOperators(s);

    //make sure that the tokenization is correct (correct num of tokens)
    assert(testingVector.size() == 5);

    //make sure the tokens were made correctly
    for (unsigned int i = 0; i < 5; ++i) assert(testingVector[i] == testArr[i]);
    //-----------------------------------------------------------------------------

    return 0;
}