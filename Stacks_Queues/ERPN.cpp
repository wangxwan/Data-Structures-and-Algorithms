# include <vector>
# include <string>
# include <stack>
# include <cstdio>
# include <iostream>
# include <regex>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> parameters;
        int para1, para2;
        for (auto s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                para2 = parameters.top();
                parameters.pop();
                para1 = parameters.top();
                parameters.pop();
                if (s == "+") parameters.push(para1 + para2);
                else if (s == "-") parameters.push(para1 - para2);
                else if (s == "*") parameters.push(para1 * para2);
                else parameters.push(para1 / para2);
            }
            else parameters.push(stoi(s));
        }
        return parameters.top();
    }
};

int main()
{
    while(true) {
        printf("tokens = ");
        string input;
        if (!(cin >> input)) break;
        vector<string> tokens;
        regex pattern(R"(\"([^"]+)\")");
        smatch result;
        while(regex_search(input, result, pattern)) {
            tokens.push_back(result[1]);
            input = result.suffix().str();
        }
        Solution obj;
        printf("%d\n", obj.evalRPN(tokens));
        tokens.clear();
    }
    return 0;
}