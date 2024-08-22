# include <vector>
# include <unordered_map>
# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsIndex;
        for (int i = 0; i < nums.size(); i++) {
            if (numsIndex.find(target - nums[i]) != numsIndex.end()) {
                return {numsIndex[target - nums[i]], i};
            }
            numsIndex[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    while(true) {
        printf("nums = ");
        string input;
        if (!getline(cin, input)) break;
        string number;
        vector<int> nums;
        for (auto c : input) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    nums.push_back(stoi(number));
                    number.clear();
                }
            }
        }
        printf("target = ");
        int target;
        if (scanf("%d", &target) != 1) break;
        getline(cin, input);
        Solution obj;
        vector<int> result = obj.twoSum(nums, target);
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