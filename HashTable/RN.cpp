# include <string>
# include <vector>
# include <cstdio>
# include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        int count[26] = {0};
        for (auto c : magazine) {
            count[c - 'a']++;
        }
        for (auto c : ransomNote) {
            if (count[c - 'a'] == 0) return false;
            count[c - 'a']--;
        }
        return true;
    }
};

int main()
{
    while(true) {
        printf("ransomNote = ");
        string input;
        if (!getline(cin, input)) break;
        string ransomNote = input.substr(1, input.size() - 2);
        printf("magazine = ");
        if (!getline(cin, input)) break;
        string magazine = input.substr(1, input.size() - 2);
        Solution obj;
        if (obj.canConstruct(ransomNote, magazine)) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}