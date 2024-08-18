# include <vector>
# include <iostream>
# include <cstdio>
# include <regex>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX;
        int sum = 0;
        for (int leftSide = 0, rightSide = 0; rightSide < nums.size(); rightSide++) {
            sum += nums[rightSide];
            while(sum >= target) {
                length = min(length, rightSide - leftSide + 1);
                sum -= nums[leftSide++];
            }
        }
        return length != INT_MAX ? length : 0;
    }
};

int main()
{
    while(cin.good()) {
        printf("target = ");
        int target;
        if (!scanf("%d", &target)) {
            break;
        }
        string input;
        getline(cin, input);
        printf("nums = ");
        vector<int> nums;
        getline(cin, input);
        regex pattern("-?[0-9]+");
        smatch result;
        while(regex_search(input, result, pattern)) {
            nums.push_back(stoi(result[0]));
            input = result.suffix().str();
        }
        Solution obj;
        printf("%d\n", obj.minSubArrayLen(target, nums));
        nums.clear();
    }
    return 0;
}