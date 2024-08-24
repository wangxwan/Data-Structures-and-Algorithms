# include <string>
# include <vector>
# include <cstdio>
# include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> next(s.size());
        int j = 0;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while(j != 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
        if (next[s.size() - 1] == 0 || s.size() % (s.size() - next[s.size() - 1])) return false;
        else return true;
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
        if (obj.repeatedSubstringPattern(s)) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}