# include <cstdio>
# include <iostream>
# include <regex>
# include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        result[0] = binarySearch(nums, target, true);
        result[1] = binarySearch(nums, target, false);
        return result;
    }
    int binarySearch(vector<int>& nums, int target, bool isSearchLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;
        while(left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                result = middle;
                if (isSearchLeft) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
        }
        return result;
    }
};

int main()
{
    while(cin.good()) {
        printf("nums = ");
        vector<int> nums;
        string input;
        getline(cin, input);
        regex pattern("-?[0-9]+");
        smatch(result);
        while(regex_search(input, result, pattern)) {
            nums.push_back(stoi(result[0]));
            input = result.suffix().str();
        }
        printf("target = ");
        int target;
        scanf("%d", &target);
        getline(cin, input);
        Solution obj;
        printf("[%d,%d]\n", obj.searchRange(nums, target)[0], obj.searchRange(nums, target)[1]);
        nums.clear();
    }
    return 0;
}