# include <cstdio>
# include <string>
# include <iostream>
# include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> count;
        for (auto c : s) {
            count[c]++;
        }
        for (auto c : t) {
            if (count.find(c) == count.end() || count[c] == 0) return false;
            count[c]--;
        }
        return true;
    }
};

int main()
{
    while(true) {
        printf("s = ");
        string input;
        if (!getline(cin, input)) break;
        string s = input.substr(1, input.size() - 2);
        printf("t = ");
        if (!getline(cin, input)) break;
        string t = input.substr(1, input.size() - 2);
        Solution obj;
        if (obj.isAnagram(s, t)) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}