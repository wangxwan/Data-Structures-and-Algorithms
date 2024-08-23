# include <string>
# include <vector>
# include <cstdio>
# include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next(needle.size());
        int j = 0;
        next[0] = j;
        for (int i = 1; i < needle.size(); i++) {
            while(j > 0 && needle[i] != needle[j]) {
                j = next[j - 1];
            }
            if (needle[i] == needle[j]) {
                j++;
            }
            next[i] = j;
        }
        j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

int main()
{
    while(true) {
        printf("haystack = ");
        string haystack;
        if (!(cin >> haystack)) break;
        haystack = haystack.substr(1, haystack.size() - 2);
        printf("needle = ");
        string needle;
        if (!(cin >> needle)) break;
        needle = needle.substr(1, needle.size() - 2);
        Solution obj;
        printf("%d\n", obj.strStr(haystack, needle));
    }
    return 0;
}