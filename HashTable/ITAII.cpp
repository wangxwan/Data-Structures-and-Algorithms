# include <vector>
# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int count[1001] = {0};
        for (auto i : nums1) {
            count[i]++;
        }
        for (auto i : nums2) {
            if (count[i] > 0) {
                result.push_back(i);
                count[i]--;
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
        vector<int> nums1, nums2;
        if (!getline(cin, input)) break;
        string number;
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
        vector<int> result = obj.intersect(nums1, nums2);
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