# include <string>
# include <stack>
# include <cstdio>
# include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> match;
        for (auto c : s) {
            if (c == '(') match.push(')');
            else if (c == '[') match.push(']');
            else if (c == '{') match.push('}');
            else {
                if (match.empty()) return false;
                else if (match.top() != c) return false;
                else match.pop();
            }
        }
        if (!match.empty()) return false;
        return true;
    }
};

int main()
{
    while(true) {
        printf("s = ");
        string s;
        if (!(cin >> s)) break;
        s = s.substr(1, s.size() - 2);
        Solution obj;
        if (obj.isValid(s)) printf("true\n");
        else printf("false\n");
    }
    return 0;
}