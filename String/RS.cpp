# include <vector>
# include <cstdio>
# include <string>
# include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right) {
            swap(s[left++], s[right--]);
        }
    }
};

int main()
{
    while(true) {
        printf("s = ");
        string input;
        if (!getline(cin, input)) break;
        vector<char> s;
        for (int i = 2; i < input.size(); i += 4) {
            s.push_back(input[i]);
        }
        Solution obj;
        obj.reverseString(s);
        printf("[");
        for (int i = 0; i < s.size(); i++) {
            printf("\"%c\"", s[i]);
            if (i != s.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}