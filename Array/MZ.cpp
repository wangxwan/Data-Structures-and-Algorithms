# include <vector>
# include <iostream>
# include <cstdio>
# include <regex>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (nums[fastIndex] != 0) {
                int temp = nums[slowIndex];
                nums[slowIndex++] = nums[fastIndex];
                nums[fastIndex] = temp;
            }
        }
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
        obj.moveZeroes(nums);
        printf("[");
        for (int i = 0; i < nums.size(); i++) {
            printf("%d", nums[i]);
            if (i != nums.size() - 1) {
                printf(",");
            }
        }
        printf("]\n");
        nums.clear();
    }
    return 0;
}