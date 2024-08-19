# include <string>
# include <vector>
# include <iostream>
# include <cstdio>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        vector<int> sub(64, 0), lst(64, 0);
        for (char c : t) {
            int i = 0x3f & c;
            lst[i]++;
        }
        int count = 0;
        int minLength = INT_MAX;
        int minLeft = 0;
        int leftSide = 0;
        for (int rightSide = 0; rightSide < m; rightSide++) {
            int i = 0x3f & s[rightSide];
            sub[i]++;
            if (sub[i] <= lst[i]) count++;
            if (count == n) {
                while(sub[0x3f & s[leftSide]] > lst[0x3f & s[leftSide]]) {
                    sub[0x3f & s[leftSide++]]--;
                }
                if (rightSide - leftSide + 1 < minLength) {
                    minLength = rightSide - leftSide + 1;
                    minLeft = leftSide;
                }
            }
        }
        if (minLength == INT_MAX) return "";
        return s.substr(minLeft, minLength);
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
        printf("\"%s\"\n", (obj.minWindow(s, t)).c_str());
    }
    return 0;
}