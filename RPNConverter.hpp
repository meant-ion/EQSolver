#include <string>
#include <map>
#include <tuple>
#include <algorithm>
#include <vector>

class RPNConverter {
    public:
        std::vector<std::string> convertToRPN(std::string infixEq);
        std::vector<std::string> tokenizeViaOperators(std::string eq);
        RPNConverter();
    private:
        std::string lastEqConverted;
        std::map<char, std::tuple<int, std::string>> operatorDictionary;

        //the index of the variable within the equation vector
        int varIndex = -1;

        //the list of operators we can use for equations
        const char ops[6] = {'^','*','/','+','-','='};
        
        bool isNumber(const std::string& s) {
            for (const char &c : s) if (std::isdigit(c) == 0) return false;
            return true;
        }

        int indexOf(std::string str, std::string substr);

        int indexOf(std::string arr[], std::string str);
};