# include <vector>
# include <iostream>
# include <cstdio>
# include <regex>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        for (int resultRightIndex = nums.size() - 1; resultRightIndex >= 0; resultRightIndex--) {
            if (nums[leftIndex] * nums[leftIndex] >= nums[rightIndex] * nums[rightIndex]) {
                result[resultRightIndex] = nums[leftIndex] * nums[leftIndex];
                leftIndex++;
            } else {
                result[resultRightIndex] = nums[rightIndex] * nums[rightIndex];
                rightIndex--;
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
        smatch result;
        while(regex_search(input, result, pattern)) {
            nums.push_back(stoi(result[0]));
            input = result.suffix().str();
        }
        Solution obj;
        nums = obj.sortedSquares(nums);
        printf("[");
        for (int i = 0; i < nums.size(); i++) {
            printf("%d", nums[i]);
            if (i != nums.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
    }
    return 0;
}