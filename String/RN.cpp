# include <string>
# include <iostream>
# include <cstdio>
using namespace std;

/*** need new string
 * int main()
 * {
 *     string s;
 *     getline(cin, s);
 *     string result;
 *     for (auto c : s) {
 *         if (isdigit(c)) {
 *             result.append("number");
 *         } else {
 *             result.push_back(c);
 *         }
 *     }
 *     printf("%s\n", result.c_str());
 *     return 0;
 * }
***/

int main()
{
    string s;
    getline(cin, s);
    int digit = 0;
    for (auto c : s) {
        if (isdigit(c)) {
            digit++;
        }
    }
    int left = s.size() - 1;
    s.resize(s.size() + digit * 5);
    int right = s.size() - 1;
    while(left >= 0) {
        if (isdigit(s[left])) {
            s[right--] = 'r';
            s[right--] = 'e';
            s[right--] = 'b';
            s[right--] = 'm';
            s[right--] = 'u';
            s[right--] = 'n';
            left--;
        } else {
            s[right--] = s[left--];
        }
    }
    printf("%s", s.c_str());
    return 0;
}