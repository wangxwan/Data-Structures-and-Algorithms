# include <vector>
# include <unordered_set>
# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int count[1001] = {0};
        for (auto i : nums1) {
            count[i] = 1;
        }
        for (auto i : nums2) {
            if (count[i] == 1) {
                result.push_back(i);
                count[i] = 0;
            }
        }
        return result;
    }
};

int main()
{
    while(true) {
        printf("nums1 = ");
        string input;
        if (!getline(cin, input)) break;
        string number;
        vector<int> nums1;
        for (auto c : input) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    nums1.push_back(stoi(number));
                    number.clear();
                }
            }
        }
        printf("nums2 = ");
        if (!getline(cin, input)) break;
        vector<int> nums2;
        for (auto c : input) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    nums2.push_back(stoi(number));
                    number.clear();
                }
            }
        }
        Solution obj;
        vector<int> result = obj.intersection(nums1, nums2);
        printf("[");
        for (auto it = result.begin(); it != result.end(); it++) {
            printf("%d", *it);
            if (*it != result.back()) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}