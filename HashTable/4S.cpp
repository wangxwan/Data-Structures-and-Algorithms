# include <vector>
# include <algorithm>
# include <cstdio>
# include <iostream>
# include <regex>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < nums.size(); a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;
            for (int b = a + 1; b < nums.size(); b++) {
                if (b > a + 1 && nums[b] == nums[b - 1]) continue;
                int left = b + 1;
                int right = nums.size() - 1;
                while(left < right) {
                    if ((long long) nums[a] + nums[b] + nums[left] + nums[right] < target) left++;
                    else if ((long long) nums[a] + nums[b] + nums[left] + nums[right] > target) right--;
                    else {
                        result.push_back({nums[a], nums[b], nums[left], nums[right]});
                        while(left < right && nums[left + 1] == nums[left]) left++;
                        while(left < right && nums[right - 1] == nums[right]) right--;
                        left++;
                        right--;
                    }
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
        string input;
        vector<int> nums;
        if (!getline(cin, input)) break;
        regex pattern("-?[0-9]+");
        smatch match;
        while(regex_search(input, match, pattern)) {
            nums.push_back(stoi(match[0]));
            input = match.suffix().str();
        }
        printf("target = ");
        int target;
        scanf("%d", &target);
        getline(cin, input);
        Solution obj;
        vector<vector<int>> result = obj.fourSum(nums, target);
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