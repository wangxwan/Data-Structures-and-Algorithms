# include <vector>
# include <algorithm>
# include <cstdio>
# include <iostream>
# include <regex>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) left++;
                else if (nums[i] + nums[left] + nums[right] > 0) right--;
                else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left + 1] == nums[left]) left++;
                    while(left < right && nums[right - 1] == nums[right]) right--;
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};

int main()
{
    while(true) {
        printf("nums = ");
        vector<int> nums;
        string input;
        if (!getline(cin, input)) break;
        regex pattern("-?[0-9]+");
        smatch match;
        while(regex_search(input, match, pattern)) {
            nums.push_back(stoi(match[0]));
            input = match.suffix().str();
        }
        Solution obj;
        vector<vector<int>> result = obj.threeSum(nums);
        printf("[");
        for (int i = 0; i < result.size(); i++) {
            printf("[");
            for (int j = 0; j < result[i].size(); j++) {
                printf("%d", result[i][j]);
                if (j != result[i].size() - 1) {
                    printf(",");
                }
            }
            printf("]");
            if (i != result.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}