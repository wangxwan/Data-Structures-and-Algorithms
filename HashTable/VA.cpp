# include <cstdio>
# include <iostream>
# include <string>
# include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        int record[26] = {0};
        for (auto c : s) {
            record[c - 'a']++;
        }
        for (auto c : t) {
            if (record[c - 'a'] == 0) return false;
            record[c - 'a']--;
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