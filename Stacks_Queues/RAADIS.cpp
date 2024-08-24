# include <string>
# include <stack>
# include <cstdio>
# include <iostream>
# include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> match;
        for (auto c : s) {
            if (match.empty() || match.top() != c) match.push(c);
            else match.pop();
        }
        s.clear();
        while(!match.empty()) {
            s += match.top();
            match.pop();
        }
        reverse(s.begin(), s.end());
        return s;
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
        s = obj.removeDuplicates(s);
        printf("\"%s\"\n", s.c_str());
    }
    return 0;
}