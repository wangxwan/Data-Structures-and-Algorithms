# include <vector>
# include <string>
# include <unordered_map>
# include <algorithm>
# include <cstdio>
# include <iostream>
# include <regex>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> group;
        for (auto s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        for (auto kv : group) {
            result.push_back(kv.second);
        }
        return result;
    }
};

int main()
{
    while(true) {
        printf("strs = ");
        string input;
        if (!getline(cin, input)) break;
        regex pattern("[a-z]+");
        smatch match;
        vector<string> strs;
        while(regex_search(input, match, pattern)) {
            strs.push_back(match[0]);
            input = match.suffix().str();
        }
        Solution obj;
        vector<vector<string>> result = obj.groupAnagrams(strs);
        if (strs.empty()) {
            printf("[[\"\"]]\n");
        } else {
            printf("[[");
            for (int i = 0; i < result.size(); i++) {
                for (int j = 0; j < result[i].size(); j++) {
                    printf("\"%s\"", result[i][j].c_str());
                    if (j != result[i].size() - 1) {
                        printf(",");
                    } else {
                        printf("]");
                    }
                }
                if (i != result.size() - 1) {
                    printf(",[");
                } else {
                    printf("]\n");
                }
            }
        }
        strs.clear();
        result.clear();
    }
    return 0;
}