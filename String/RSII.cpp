# include <string>
# include <cstdio>
# include <iostream>
using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end) {
        while(start < end) {
            swap(s[start++], s[end--]);
        }
    }
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k < s.size()) {
                reverse(s, i, i + k - 1);
            } else {
                reverse(s, i, s.size() - 1);
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
        printf("k = ");
        int k;
        scanf("%d", &k);
        Solution obj;
        string result = obj.reverseStr(s, k);
        getline(cin, s);
        printf("\"%s\"\n", result.c_str());
    }
    return 0;
}