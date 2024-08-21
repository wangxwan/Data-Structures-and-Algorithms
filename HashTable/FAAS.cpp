# include <vector>
# include <string>
# include <unordered_map>
# include <cstdio>
# include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> count(26, 0);
        for (auto c : p) {
            count[c - 'a']++;
        }
        int left = 0;
        vector<int> window(26, 0);
        for (int right = 0; right < s.size(); right++) {
            window[s[right] - 'a']++;
            if (right - left + 1 ==  p.size()) {
                if (window == count) {
                    result.push_back(left);
                }
                window[s[left++] - 'a']--;
            }
        }
        return result;
    }
};

int main()
{
    while(true) {
        printf("s = ");
        string input;
        if (!getline(cin, input)) break;
        string s = input.substr(1, input.size() - 2);
        printf("p = ");
        if (!getline(cin, input)) break;
        string p = input.substr(1, input.size() - 2);
        Solution obj;
        vector<int> result = obj.findAnagrams(s, p);
        printf("[");
        for (int i = 0; i < result.size(); i++) {
            printf("%d", result[i]);
            if (i != result.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}