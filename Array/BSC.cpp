# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sizeS = backspace(s);
        int sizeT = backspace(t);
        if (sizeS != sizeT) {
            return false;
        } else {
            for (int i = 0; i < sizeS; i++) {
                if (s[i] != t[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    int backspace(string& s) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < s.size(); fastIndex++) {
            if (s[fastIndex] != '#') {
                s[slowIndex++] = s[fastIndex];
            } else if (slowIndex != 0) {
                slowIndex--;
            }
        }
        return slowIndex;
    }
};

int main()
{
    while(cin.good()) {
        printf("s = ");
        string s, t, input;
        getline(cin, input);
        size_t firstQuoteS = input.find('"');
        size_t lastQuoteS = input.rfind('"');
        s = input.substr(firstQuoteS + 1, lastQuoteS - firstQuoteS - 1);
        printf("t = ");
        getline(cin, input);
        size_t firstQuoteT = input.find('"');
        size_t lastQuoteT = input.rfind('"');
        t = input.substr(firstQuoteT + 1, lastQuoteT - firstQuoteT - 1);
        Solution obj;
        if(obj.backspaceCompare(s, t)) {
            printf("true\n");
        } else printf("false\n");
    }
    return 0;
}