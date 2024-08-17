# include <cstdio>
# include <iostream>
# include <regex>
# include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                return middle;
            }
        }
        return -1;
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
        smatch result;
        while (regex_search(input, result, pattern)) {
            nums.push_back(stoi(result[0]));
            input = result.suffix().str();
        }
        printf("target = ");
        int target;
        scanf("%d", &target);
        getline(cin, input);
        Solution obj;
        printf("%d\n", obj.search(nums, target));
        nums.clear();
    }
    return 0;
}
