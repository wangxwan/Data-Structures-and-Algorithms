# include <string>
# include <cstdio>
# include <iostream>
using namespace std;

class Solution {
public:
    void adjustSpace(string& s) {
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            if (s[right] != ' ') {
                if (left != 0) {
                    s[left++] = ' ';
                }
                while(s[right] != ' ' && right < s.size()) {
                    s[left++] = s[right++];
                }
            }
        }
        s.resize(left);
    }

    void reverse(string& s, int left, int right) {
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }

    string reverseWords(string s) {
        adjustSpace(s);
        reverse(s, 0, s.size() - 1);
        int left = 0;
        for (int right = 0; right <= s.size(); right++) {
            if (s[right] == ' ' || right == s.size()) {
                reverse(s, left, right - 1);
                left = right + 1;
            }
        }
        return s;
    }
};

int main()
{
    while(true) {
        printf("s = ");
        string s;
        if (!getline(cin, s)) break;
        s = s.substr(1, s.size() - 2);
        Solution obj;
        printf("\"%s\"\n", obj.reverseWords(s).c_str());
    }
    return 0;
}